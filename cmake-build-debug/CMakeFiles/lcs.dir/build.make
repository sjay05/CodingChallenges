# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alpha/Desktop/DsAlgoC++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alpha/Desktop/DsAlgoC++/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lcs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lcs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lcs.dir/flags.make

CMakeFiles/lcs.dir/Algorithms/Recursion/lcs.cpp.o: CMakeFiles/lcs.dir/flags.make
CMakeFiles/lcs.dir/Algorithms/Recursion/lcs.cpp.o: ../Algorithms/Recursion/lcs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alpha/Desktop/DsAlgoC++/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lcs.dir/Algorithms/Recursion/lcs.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lcs.dir/Algorithms/Recursion/lcs.cpp.o -c /Users/alpha/Desktop/DsAlgoC++/Algorithms/Recursion/lcs.cpp

CMakeFiles/lcs.dir/Algorithms/Recursion/lcs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lcs.dir/Algorithms/Recursion/lcs.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alpha/Desktop/DsAlgoC++/Algorithms/Recursion/lcs.cpp > CMakeFiles/lcs.dir/Algorithms/Recursion/lcs.cpp.i

CMakeFiles/lcs.dir/Algorithms/Recursion/lcs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lcs.dir/Algorithms/Recursion/lcs.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alpha/Desktop/DsAlgoC++/Algorithms/Recursion/lcs.cpp -o CMakeFiles/lcs.dir/Algorithms/Recursion/lcs.cpp.s

# Object files for target lcs
lcs_OBJECTS = \
"CMakeFiles/lcs.dir/Algorithms/Recursion/lcs.cpp.o"

# External object files for target lcs
lcs_EXTERNAL_OBJECTS =

lcs: CMakeFiles/lcs.dir/Algorithms/Recursion/lcs.cpp.o
lcs: CMakeFiles/lcs.dir/build.make
lcs: CMakeFiles/lcs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/alpha/Desktop/DsAlgoC++/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lcs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lcs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lcs.dir/build: lcs

.PHONY : CMakeFiles/lcs.dir/build

CMakeFiles/lcs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lcs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lcs.dir/clean

CMakeFiles/lcs.dir/depend:
	cd /Users/alpha/Desktop/DsAlgoC++/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alpha/Desktop/DsAlgoC++ /Users/alpha/Desktop/DsAlgoC++ /Users/alpha/Desktop/DsAlgoC++/cmake-build-debug /Users/alpha/Desktop/DsAlgoC++/cmake-build-debug /Users/alpha/Desktop/DsAlgoC++/cmake-build-debug/CMakeFiles/lcs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lcs.dir/depend
