# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /media/vincent/DATA/Ubuntu/Project/vlib/example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/vincent/DATA/Ubuntu/Project/vlib/example/temp

# Include any dependencies generated for this target.
include DesignPattern/CMakeFiles/observer_test.dir/depend.make

# Include the progress variables for this target.
include DesignPattern/CMakeFiles/observer_test.dir/progress.make

# Include the compile flags for this target's objects.
include DesignPattern/CMakeFiles/observer_test.dir/flags.make

DesignPattern/CMakeFiles/observer_test.dir/observer_test.cpp.o: DesignPattern/CMakeFiles/observer_test.dir/flags.make
DesignPattern/CMakeFiles/observer_test.dir/observer_test.cpp.o: ../DesignPattern/observer_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/vincent/DATA/Ubuntu/Project/vlib/example/temp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object DesignPattern/CMakeFiles/observer_test.dir/observer_test.cpp.o"
	cd /media/vincent/DATA/Ubuntu/Project/vlib/example/temp/DesignPattern && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/observer_test.dir/observer_test.cpp.o -c /media/vincent/DATA/Ubuntu/Project/vlib/example/DesignPattern/observer_test.cpp

DesignPattern/CMakeFiles/observer_test.dir/observer_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/observer_test.dir/observer_test.cpp.i"
	cd /media/vincent/DATA/Ubuntu/Project/vlib/example/temp/DesignPattern && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/vincent/DATA/Ubuntu/Project/vlib/example/DesignPattern/observer_test.cpp > CMakeFiles/observer_test.dir/observer_test.cpp.i

DesignPattern/CMakeFiles/observer_test.dir/observer_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/observer_test.dir/observer_test.cpp.s"
	cd /media/vincent/DATA/Ubuntu/Project/vlib/example/temp/DesignPattern && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/vincent/DATA/Ubuntu/Project/vlib/example/DesignPattern/observer_test.cpp -o CMakeFiles/observer_test.dir/observer_test.cpp.s

DesignPattern/CMakeFiles/observer_test.dir/observer_test.cpp.o.requires:

.PHONY : DesignPattern/CMakeFiles/observer_test.dir/observer_test.cpp.o.requires

DesignPattern/CMakeFiles/observer_test.dir/observer_test.cpp.o.provides: DesignPattern/CMakeFiles/observer_test.dir/observer_test.cpp.o.requires
	$(MAKE) -f DesignPattern/CMakeFiles/observer_test.dir/build.make DesignPattern/CMakeFiles/observer_test.dir/observer_test.cpp.o.provides.build
.PHONY : DesignPattern/CMakeFiles/observer_test.dir/observer_test.cpp.o.provides

DesignPattern/CMakeFiles/observer_test.dir/observer_test.cpp.o.provides.build: DesignPattern/CMakeFiles/observer_test.dir/observer_test.cpp.o


# Object files for target observer_test
observer_test_OBJECTS = \
"CMakeFiles/observer_test.dir/observer_test.cpp.o"

# External object files for target observer_test
observer_test_EXTERNAL_OBJECTS =

/media/vincent/DATA/Ubuntu/Project/vlib/bin/DesignPattern/observer_test: DesignPattern/CMakeFiles/observer_test.dir/observer_test.cpp.o
/media/vincent/DATA/Ubuntu/Project/vlib/bin/DesignPattern/observer_test: DesignPattern/CMakeFiles/observer_test.dir/build.make
/media/vincent/DATA/Ubuntu/Project/vlib/bin/DesignPattern/observer_test: ../DesignPattern/../../lib/libVLib.so
/media/vincent/DATA/Ubuntu/Project/vlib/bin/DesignPattern/observer_test: DesignPattern/CMakeFiles/observer_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/vincent/DATA/Ubuntu/Project/vlib/example/temp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /media/vincent/DATA/Ubuntu/Project/vlib/bin/DesignPattern/observer_test"
	cd /media/vincent/DATA/Ubuntu/Project/vlib/example/temp/DesignPattern && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/observer_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
DesignPattern/CMakeFiles/observer_test.dir/build: /media/vincent/DATA/Ubuntu/Project/vlib/bin/DesignPattern/observer_test

.PHONY : DesignPattern/CMakeFiles/observer_test.dir/build

DesignPattern/CMakeFiles/observer_test.dir/requires: DesignPattern/CMakeFiles/observer_test.dir/observer_test.cpp.o.requires

.PHONY : DesignPattern/CMakeFiles/observer_test.dir/requires

DesignPattern/CMakeFiles/observer_test.dir/clean:
	cd /media/vincent/DATA/Ubuntu/Project/vlib/example/temp/DesignPattern && $(CMAKE_COMMAND) -P CMakeFiles/observer_test.dir/cmake_clean.cmake
.PHONY : DesignPattern/CMakeFiles/observer_test.dir/clean

DesignPattern/CMakeFiles/observer_test.dir/depend:
	cd /media/vincent/DATA/Ubuntu/Project/vlib/example/temp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/vincent/DATA/Ubuntu/Project/vlib/example /media/vincent/DATA/Ubuntu/Project/vlib/example/DesignPattern /media/vincent/DATA/Ubuntu/Project/vlib/example/temp /media/vincent/DATA/Ubuntu/Project/vlib/example/temp/DesignPattern /media/vincent/DATA/Ubuntu/Project/vlib/example/temp/DesignPattern/CMakeFiles/observer_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : DesignPattern/CMakeFiles/observer_test.dir/depend
