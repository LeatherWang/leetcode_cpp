# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = /home/leather/lxdata/leather_repertory/leecode/3_Longest_Substring_Without_Repeating_Characters/longest_substring

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leather/lxdata/leather_repertory/leecode/3_Longest_Substring_Without_Repeating_Characters/longest_substring

# Include any dependencies generated for this target.
include CMakeFiles/vector_compare.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vector_compare.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vector_compare.dir/flags.make

CMakeFiles/vector_compare.dir/main.cpp.o: CMakeFiles/vector_compare.dir/flags.make
CMakeFiles/vector_compare.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leather/lxdata/leather_repertory/leecode/3_Longest_Substring_Without_Repeating_Characters/longest_substring/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vector_compare.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vector_compare.dir/main.cpp.o -c /home/leather/lxdata/leather_repertory/leecode/3_Longest_Substring_Without_Repeating_Characters/longest_substring/main.cpp

CMakeFiles/vector_compare.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vector_compare.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leather/lxdata/leather_repertory/leecode/3_Longest_Substring_Without_Repeating_Characters/longest_substring/main.cpp > CMakeFiles/vector_compare.dir/main.cpp.i

CMakeFiles/vector_compare.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vector_compare.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leather/lxdata/leather_repertory/leecode/3_Longest_Substring_Without_Repeating_Characters/longest_substring/main.cpp -o CMakeFiles/vector_compare.dir/main.cpp.s

CMakeFiles/vector_compare.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/vector_compare.dir/main.cpp.o.requires

CMakeFiles/vector_compare.dir/main.cpp.o.provides: CMakeFiles/vector_compare.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/vector_compare.dir/build.make CMakeFiles/vector_compare.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/vector_compare.dir/main.cpp.o.provides

CMakeFiles/vector_compare.dir/main.cpp.o.provides.build: CMakeFiles/vector_compare.dir/main.cpp.o


# Object files for target vector_compare
vector_compare_OBJECTS = \
"CMakeFiles/vector_compare.dir/main.cpp.o"

# External object files for target vector_compare
vector_compare_EXTERNAL_OBJECTS =

vector_compare: CMakeFiles/vector_compare.dir/main.cpp.o
vector_compare: CMakeFiles/vector_compare.dir/build.make
vector_compare: CMakeFiles/vector_compare.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leather/lxdata/leather_repertory/leecode/3_Longest_Substring_Without_Repeating_Characters/longest_substring/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable vector_compare"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vector_compare.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vector_compare.dir/build: vector_compare

.PHONY : CMakeFiles/vector_compare.dir/build

CMakeFiles/vector_compare.dir/requires: CMakeFiles/vector_compare.dir/main.cpp.o.requires

.PHONY : CMakeFiles/vector_compare.dir/requires

CMakeFiles/vector_compare.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vector_compare.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vector_compare.dir/clean

CMakeFiles/vector_compare.dir/depend:
	cd /home/leather/lxdata/leather_repertory/leecode/3_Longest_Substring_Without_Repeating_Characters/longest_substring && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leather/lxdata/leather_repertory/leecode/3_Longest_Substring_Without_Repeating_Characters/longest_substring /home/leather/lxdata/leather_repertory/leecode/3_Longest_Substring_Without_Repeating_Characters/longest_substring /home/leather/lxdata/leather_repertory/leecode/3_Longest_Substring_Without_Repeating_Characters/longest_substring /home/leather/lxdata/leather_repertory/leecode/3_Longest_Substring_Without_Repeating_Characters/longest_substring /home/leather/lxdata/leather_repertory/leecode/3_Longest_Substring_Without_Repeating_Characters/longest_substring/CMakeFiles/vector_compare.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vector_compare.dir/depend

