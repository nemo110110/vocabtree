# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/psastras/vocabtree/3rdparty/philbinj-fastann

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/psastras/vocabtree/3rdparty/philbinj-fastann

# Include any dependencies generated for this target.
include CMakeFiles/perf_kdtree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/perf_kdtree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/perf_kdtree.dir/flags.make

CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.o: CMakeFiles/perf_kdtree.dir/flags.make
CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.o: perf_kdtree.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/psastras/vocabtree/3rdparty/philbinj-fastann/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.o"
	/usr/lib64/ccache/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.o -c /home/psastras/vocabtree/3rdparty/philbinj-fastann/perf_kdtree.cpp

CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.i"
	/usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/psastras/vocabtree/3rdparty/philbinj-fastann/perf_kdtree.cpp > CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.i

CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.s"
	/usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/psastras/vocabtree/3rdparty/philbinj-fastann/perf_kdtree.cpp -o CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.s

CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.o.requires:
.PHONY : CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.o.requires

CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.o.provides: CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.o.requires
	$(MAKE) -f CMakeFiles/perf_kdtree.dir/build.make CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.o.provides.build
.PHONY : CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.o.provides

CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.o.provides.build: CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.o

# Object files for target perf_kdtree
perf_kdtree_OBJECTS = \
"CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.o"

# External object files for target perf_kdtree
perf_kdtree_EXTERNAL_OBJECTS =

perf_kdtree: CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.o
perf_kdtree: CMakeFiles/perf_kdtree.dir/build.make
perf_kdtree: libfastann.so
perf_kdtree: CMakeFiles/perf_kdtree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable perf_kdtree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/perf_kdtree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/perf_kdtree.dir/build: perf_kdtree
.PHONY : CMakeFiles/perf_kdtree.dir/build

CMakeFiles/perf_kdtree.dir/requires: CMakeFiles/perf_kdtree.dir/perf_kdtree.cpp.o.requires
.PHONY : CMakeFiles/perf_kdtree.dir/requires

CMakeFiles/perf_kdtree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/perf_kdtree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/perf_kdtree.dir/clean

CMakeFiles/perf_kdtree.dir/depend:
	cd /home/psastras/vocabtree/3rdparty/philbinj-fastann && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/psastras/vocabtree/3rdparty/philbinj-fastann /home/psastras/vocabtree/3rdparty/philbinj-fastann /home/psastras/vocabtree/3rdparty/philbinj-fastann /home/psastras/vocabtree/3rdparty/philbinj-fastann /home/psastras/vocabtree/3rdparty/philbinj-fastann/CMakeFiles/perf_kdtree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/perf_kdtree.dir/depend

