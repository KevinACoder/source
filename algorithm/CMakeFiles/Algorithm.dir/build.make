# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/WorkSpace/source/algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/WorkSpace/source/algorithm

# Include any dependencies generated for this target.
include CMakeFiles/Algorithm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Algorithm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Algorithm.dir/flags.make

CMakeFiles/Algorithm.dir/run.cpp.o: CMakeFiles/Algorithm.dir/flags.make
CMakeFiles/Algorithm.dir/run.cpp.o: run.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/WorkSpace/source/algorithm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Algorithm.dir/run.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Algorithm.dir/run.cpp.o -c /home/pi/WorkSpace/source/algorithm/run.cpp

CMakeFiles/Algorithm.dir/run.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Algorithm.dir/run.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/WorkSpace/source/algorithm/run.cpp > CMakeFiles/Algorithm.dir/run.cpp.i

CMakeFiles/Algorithm.dir/run.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Algorithm.dir/run.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/WorkSpace/source/algorithm/run.cpp -o CMakeFiles/Algorithm.dir/run.cpp.s

CMakeFiles/Algorithm.dir/run.cpp.o.requires:

.PHONY : CMakeFiles/Algorithm.dir/run.cpp.o.requires

CMakeFiles/Algorithm.dir/run.cpp.o.provides: CMakeFiles/Algorithm.dir/run.cpp.o.requires
	$(MAKE) -f CMakeFiles/Algorithm.dir/build.make CMakeFiles/Algorithm.dir/run.cpp.o.provides.build
.PHONY : CMakeFiles/Algorithm.dir/run.cpp.o.provides

CMakeFiles/Algorithm.dir/run.cpp.o.provides.build: CMakeFiles/Algorithm.dir/run.cpp.o


# Object files for target Algorithm
Algorithm_OBJECTS = \
"CMakeFiles/Algorithm.dir/run.cpp.o"

# External object files for target Algorithm
Algorithm_EXTERNAL_OBJECTS =

Algorithm: CMakeFiles/Algorithm.dir/run.cpp.o
Algorithm: CMakeFiles/Algorithm.dir/build.make
Algorithm: CMakeFiles/Algorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/WorkSpace/source/algorithm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Algorithm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Algorithm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Algorithm.dir/build: Algorithm

.PHONY : CMakeFiles/Algorithm.dir/build

CMakeFiles/Algorithm.dir/requires: CMakeFiles/Algorithm.dir/run.cpp.o.requires

.PHONY : CMakeFiles/Algorithm.dir/requires

CMakeFiles/Algorithm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Algorithm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Algorithm.dir/clean

CMakeFiles/Algorithm.dir/depend:
	cd /home/pi/WorkSpace/source/algorithm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/WorkSpace/source/algorithm /home/pi/WorkSpace/source/algorithm /home/pi/WorkSpace/source/algorithm /home/pi/WorkSpace/source/algorithm /home/pi/WorkSpace/source/algorithm/CMakeFiles/Algorithm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Algorithm.dir/depend
