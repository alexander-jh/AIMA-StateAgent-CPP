# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /snap/clion/126/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/126/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/StateRover.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/StateRover.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StateRover.dir/flags.make

CMakeFiles/StateRover.dir/StateRover.cpp.o: CMakeFiles/StateRover.dir/flags.make
CMakeFiles/StateRover.dir/StateRover.cpp.o: ../StateRover.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StateRover.dir/StateRover.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StateRover.dir/StateRover.cpp.o -c /home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1/StateRover.cpp

CMakeFiles/StateRover.dir/StateRover.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StateRover.dir/StateRover.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1/StateRover.cpp > CMakeFiles/StateRover.dir/StateRover.cpp.i

CMakeFiles/StateRover.dir/StateRover.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StateRover.dir/StateRover.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1/StateRover.cpp -o CMakeFiles/StateRover.dir/StateRover.cpp.s

CMakeFiles/StateRover.dir/ReflexAgent.cpp.o: CMakeFiles/StateRover.dir/flags.make
CMakeFiles/StateRover.dir/ReflexAgent.cpp.o: ../ReflexAgent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/StateRover.dir/ReflexAgent.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StateRover.dir/ReflexAgent.cpp.o -c /home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1/ReflexAgent.cpp

CMakeFiles/StateRover.dir/ReflexAgent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StateRover.dir/ReflexAgent.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1/ReflexAgent.cpp > CMakeFiles/StateRover.dir/ReflexAgent.cpp.i

CMakeFiles/StateRover.dir/ReflexAgent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StateRover.dir/ReflexAgent.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1/ReflexAgent.cpp -o CMakeFiles/StateRover.dir/ReflexAgent.cpp.s

CMakeFiles/StateRover.dir/RoverSensors.cc.o: CMakeFiles/StateRover.dir/flags.make
CMakeFiles/StateRover.dir/RoverSensors.cc.o: ../RoverSensors.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/StateRover.dir/RoverSensors.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StateRover.dir/RoverSensors.cc.o -c /home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1/RoverSensors.cc

CMakeFiles/StateRover.dir/RoverSensors.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StateRover.dir/RoverSensors.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1/RoverSensors.cc > CMakeFiles/StateRover.dir/RoverSensors.cc.i

CMakeFiles/StateRover.dir/RoverSensors.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StateRover.dir/RoverSensors.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1/RoverSensors.cc -o CMakeFiles/StateRover.dir/RoverSensors.cc.s

# Object files for target StateRover
StateRover_OBJECTS = \
"CMakeFiles/StateRover.dir/StateRover.cpp.o" \
"CMakeFiles/StateRover.dir/ReflexAgent.cpp.o" \
"CMakeFiles/StateRover.dir/RoverSensors.cc.o"

# External object files for target StateRover
StateRover_EXTERNAL_OBJECTS =

StateRover: CMakeFiles/StateRover.dir/StateRover.cpp.o
StateRover: CMakeFiles/StateRover.dir/ReflexAgent.cpp.o
StateRover: CMakeFiles/StateRover.dir/RoverSensors.cc.o
StateRover: CMakeFiles/StateRover.dir/build.make
StateRover: CMakeFiles/StateRover.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable StateRover"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StateRover.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StateRover.dir/build: StateRover

.PHONY : CMakeFiles/StateRover.dir/build

CMakeFiles/StateRover.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/StateRover.dir/cmake_clean.cmake
.PHONY : CMakeFiles/StateRover.dir/clean

CMakeFiles/StateRover.dir/depend:
	cd /home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1 /home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1 /home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1/cmake-build-debug /home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1/cmake-build-debug /home/ajw/Dropbox/OSU/CSE3521/Labs/Lab1/cmake-build-debug/CMakeFiles/StateRover.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/StateRover.dir/depend
