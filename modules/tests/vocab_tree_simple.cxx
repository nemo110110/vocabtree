#include <config.hpp>
#include "tests_config.hpp"
#include <search/vocab_tree/vocab_tree.hpp>
#include <iostream>

#include <utils/filesystem.hpp>
#include <utils/numerics.hpp>
#include <utils/dataset.hpp>
#include <utils/vision.hpp>
#include <utils/logger.hpp>
#include <vis/matches_page.hpp>


_INITIALIZE_EASYLOGGINGPP

int main(int argc, char *argv[]) {
#if ENABLE_MULTITHREADING && ENABLE_MPI
  MPI_Init(&argc, &argv);
  int rank, procs;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &procs);
  printf("Rank: %d\n", rank);

#endif

  SimpleDataset simple_dataset(s_oxfordmini_data_dir, s_oxfordmini_database_location);
  //SimpleDataset simple_dataset("/afs/cs.cmu.edu/user/psastras/ladoga/data/oxford", "/afs/cs.cmu.edu/user/psastras/ladoga/data/oxford/db_oxford.bin");

  LINFO << simple_dataset;

  //std::stringstream vocab_output_file;
  //vocab_output_file << simple_dataset.location() << "/vocab/" << train_params->split << "-" 
    //<< train_params->depth << ".vocab";
  
  /*struct Temp {
    int asdf;
    uint64_t t;
  };
  if (rank == 0) {
    Temp t;
    t.asdf = 2;
    t.t = 100001234912734912;
    MPI_Request r;
    MPI_Isend(&t, sizeof(Temp), MPI_BYTE, 1, 0, MPI_COMM_WORLD, &r);
    MPI_Waitall(1, &r, MPI_STATUSES_IGNORE);
    printf("Send t\n");
  }
  else {
    Temp t;
    MPI_Request r;
    MPI_Irecv(&t, sizeof(Temp), MPI_BYTE, 0, 0, MPI_COMM_WORLD, &r);
    MPI_Wait(&r, MPI_STATUS_IGNORE);
    printf("Got: %d, %d\n", t.asdf, t.t);
  }*/

  VocabTree vt;
  PTR_LIB::shared_ptr<VocabTree::TrainParams> train_params = PTR_LIB::make_shared<VocabTree::TrainParams>();
  train_params->depth = 3;
  train_params->split = 6;
#if ENABLE_MULTITHREADING && ENABLE_MPI
  // have to synchronize what images the nodes build with
  int numImages = 50;
  std::vector<PTR_LIB::shared_ptr<const Image> > images(numImages);
  if(rank==0) {
    images = simple_dataset.random_images(numImages);
    std::vector<MPI_Request> requests(numImages*(procs - 1));
    std::vector<uint64_t> ids(numImages);
    for (int i = 0; i < numImages; i++) {
      ids[i] = images[i]->id;
      for (int p = 1; p < procs; p++)
        MPI_Isend(&ids[i], 1, MPI_LONG_LONG, p, i, MPI_COMM_WORLD, &requests[numImages*(p - 1) + i]);
    }
    MPI_Waitall(requests.size(), &requests[0], MPI_STATUSES_IGNORE);
  }
  else {
    uint64_t id;
    for (int i = 0; i < numImages; i++) {
      MPI_Recv(&id, 1, MPI_LONG_LONG, 0, i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      images[i] = simple_dataset.image(id);
    }
  }
#else
  std::vector<PTR_LIB::shared_ptr<const Image> > images = simple_dataset.random_images(200);
#endif
  vt.train(simple_dataset, train_params, images);

  //printf("\n%d Finished Building Tree\n\n", rank);

  PTR_LIB::shared_ptr<VocabTree::SearchParams> searchParams = PTR_LIB::make_shared<VocabTree::SearchParams>();

  searchParams->amountToReturn = 10;
  //searchParams->cutoff = 10;

  MatchesPage html_output;
  //if (rank==0)
  /*for (uint32_t i = 0; i < 20; i++) {
    PTR_LIB::shared_ptr<VocabTree::MatchResults> matches =
      std::static_pointer_cast<VocabTree::MatchResults>(vt.search(simple_dataset, searchParams, images[i]));
    if(matches == 0) continue;
    //LINFO << "Query " << i << ": " << *matches;
    printf("Matches for image %d: ", i);
    for (uint64_t id : matches->matches)
      printf("%d ", id);
    printf("\n");

    html_output.add_match(images[i]->id, matches->matches, simple_dataset);
    }*/
  std::vector< PTR_LIB::shared_ptr<const Image> > imToTest(images.begin(), images.begin() + 20);
  std::vector< PTR_LIB::shared_ptr<MatchResultsBase> > matches = vt.search(simple_dataset, searchParams, imToTest);

  for (uint32_t i = 0; i < imToTest.size(); i++) {
    if(!matches[i]) continue;
    std::cout << "SEARCH " << i << std::endl;
    std::cout << "Matches for image " << imToTest[i]->id << ":";
    for(int j=0; j<matches[i]->matches.size(); j++)
      std::cout << matches[i]->matches[j] << " ";
    std::cout << std::endl;
    html_output.add_match(images[i]->id, matches[i]->matches, simple_dataset);
  }

  html_output.write(simple_dataset.location() + "/results/matches/");

#if ENABLE_MULTITHREADING && ENABLE_MPI
  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Finalize();
#endif

  return 0;
}
