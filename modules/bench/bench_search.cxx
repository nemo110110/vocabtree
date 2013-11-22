#include "bench_config.hpp"

#include <utils/filesystem.hpp>
#include <utils/numerics.hpp>
#include <utils/dataset.hpp>
#include <utils/vision.hpp>
#include <utils/logger.hpp>
#include <utils/cycletimer.hpp>
#include <search/bag_of_words/bag_of_words.hpp>
#include <search/inverted_index/inverted_index.hpp>
#include <vis/matches_page.hpp>



_INITIALIZE_EASYLOGGINGPP

void bench_oxford() {

	MatchesPage html_output;
	
	const uint32_t num_clusters = s_oxford_num_clusters;

	SimpleDataset oxford_dataset(s_oxford_data_dir, s_oxford_database_location);
	LINFO << oxford_dataset;

	std::stringstream index_output_file;
	index_output_file << oxford_dataset.location() << "/index/" << num_clusters << ".index";
	InvertedIndex ii(index_output_file.str());

	double total_time = 0.0;
	for(uint32_t i=0; i<256; i++) {
		double start_time = CycleTimer::currentSeconds();
		std::shared_ptr<InvertedIndex::MatchResults> matches = 
		std::static_pointer_cast<InvertedIndex::MatchResults>(ii.search(oxford_dataset, nullptr, oxford_dataset.image(i)));	
		if(matches == nullptr) {
			LERROR << "Error while running search.";
			continue;
		}
		double end_time = CycleTimer::currentSeconds();
		total_time += (end_time - start_time);
		html_output.add_match(i, matches->matches, oxford_dataset);
	}

	html_output.write(oxford_dataset.location() + "/results/matches/");

}

int main(int argc, char *argv[]) {

	bench_oxford();

	return 0;
}