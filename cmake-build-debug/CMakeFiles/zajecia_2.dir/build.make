# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pobi/CLionProjects/zajecia_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pobi/CLionProjects/zajecia_2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/zajecia_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zajecia_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zajecia_2.dir/flags.make

CMakeFiles/zajecia_2.dir/src/model/Client.cpp.o: CMakeFiles/zajecia_2.dir/flags.make
CMakeFiles/zajecia_2.dir/src/model/Client.cpp.o: ../src/model/Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pobi/CLionProjects/zajecia_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zajecia_2.dir/src/model/Client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zajecia_2.dir/src/model/Client.cpp.o -c /home/pobi/CLionProjects/zajecia_2/src/model/Client.cpp

CMakeFiles/zajecia_2.dir/src/model/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zajecia_2.dir/src/model/Client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pobi/CLionProjects/zajecia_2/src/model/Client.cpp > CMakeFiles/zajecia_2.dir/src/model/Client.cpp.i

CMakeFiles/zajecia_2.dir/src/model/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zajecia_2.dir/src/model/Client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pobi/CLionProjects/zajecia_2/src/model/Client.cpp -o CMakeFiles/zajecia_2.dir/src/model/Client.cpp.s

CMakeFiles/zajecia_2.dir/src/model/Client.cpp.o.requires:

.PHONY : CMakeFiles/zajecia_2.dir/src/model/Client.cpp.o.requires

CMakeFiles/zajecia_2.dir/src/model/Client.cpp.o.provides: CMakeFiles/zajecia_2.dir/src/model/Client.cpp.o.requires
	$(MAKE) -f CMakeFiles/zajecia_2.dir/build.make CMakeFiles/zajecia_2.dir/src/model/Client.cpp.o.provides.build
.PHONY : CMakeFiles/zajecia_2.dir/src/model/Client.cpp.o.provides

CMakeFiles/zajecia_2.dir/src/model/Client.cpp.o.provides.build: CMakeFiles/zajecia_2.dir/src/model/Client.cpp.o


CMakeFiles/zajecia_2.dir/program.cpp.o: CMakeFiles/zajecia_2.dir/flags.make
CMakeFiles/zajecia_2.dir/program.cpp.o: ../program.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pobi/CLionProjects/zajecia_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/zajecia_2.dir/program.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zajecia_2.dir/program.cpp.o -c /home/pobi/CLionProjects/zajecia_2/program.cpp

CMakeFiles/zajecia_2.dir/program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zajecia_2.dir/program.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pobi/CLionProjects/zajecia_2/program.cpp > CMakeFiles/zajecia_2.dir/program.cpp.i

CMakeFiles/zajecia_2.dir/program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zajecia_2.dir/program.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pobi/CLionProjects/zajecia_2/program.cpp -o CMakeFiles/zajecia_2.dir/program.cpp.s

CMakeFiles/zajecia_2.dir/program.cpp.o.requires:

.PHONY : CMakeFiles/zajecia_2.dir/program.cpp.o.requires

CMakeFiles/zajecia_2.dir/program.cpp.o.provides: CMakeFiles/zajecia_2.dir/program.cpp.o.requires
	$(MAKE) -f CMakeFiles/zajecia_2.dir/build.make CMakeFiles/zajecia_2.dir/program.cpp.o.provides.build
.PHONY : CMakeFiles/zajecia_2.dir/program.cpp.o.provides

CMakeFiles/zajecia_2.dir/program.cpp.o.provides.build: CMakeFiles/zajecia_2.dir/program.cpp.o


# Object files for target zajecia_2
zajecia_2_OBJECTS = \
"CMakeFiles/zajecia_2.dir/src/model/Client.cpp.o" \
"CMakeFiles/zajecia_2.dir/program.cpp.o"

# External object files for target zajecia_2
zajecia_2_EXTERNAL_OBJECTS =

zajecia_2: CMakeFiles/zajecia_2.dir/src/model/Client.cpp.o
zajecia_2: CMakeFiles/zajecia_2.dir/program.cpp.o
zajecia_2: CMakeFiles/zajecia_2.dir/build.make
zajecia_2: CMakeFiles/zajecia_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pobi/CLionProjects/zajecia_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable zajecia_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zajecia_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zajecia_2.dir/build: zajecia_2

.PHONY : CMakeFiles/zajecia_2.dir/build

CMakeFiles/zajecia_2.dir/requires: CMakeFiles/zajecia_2.dir/src/model/Client.cpp.o.requires
CMakeFiles/zajecia_2.dir/requires: CMakeFiles/zajecia_2.dir/program.cpp.o.requires

.PHONY : CMakeFiles/zajecia_2.dir/requires

CMakeFiles/zajecia_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zajecia_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zajecia_2.dir/clean

CMakeFiles/zajecia_2.dir/depend:
	cd /home/pobi/CLionProjects/zajecia_2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pobi/CLionProjects/zajecia_2 /home/pobi/CLionProjects/zajecia_2 /home/pobi/CLionProjects/zajecia_2/cmake-build-debug /home/pobi/CLionProjects/zajecia_2/cmake-build-debug /home/pobi/CLionProjects/zajecia_2/cmake-build-debug/CMakeFiles/zajecia_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zajecia_2.dir/depend
