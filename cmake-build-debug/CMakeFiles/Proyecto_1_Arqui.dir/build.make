# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/169/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/169/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/carlos/CLionProjects/Proyecto_1_Arqui

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/carlos/CLionProjects/Proyecto_1_Arqui/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Proyecto_1_Arqui.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Proyecto_1_Arqui.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Proyecto_1_Arqui.dir/flags.make

CMakeFiles/Proyecto_1_Arqui.dir/main.cpp.o: CMakeFiles/Proyecto_1_Arqui.dir/flags.make
CMakeFiles/Proyecto_1_Arqui.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/carlos/CLionProjects/Proyecto_1_Arqui/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Proyecto_1_Arqui.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proyecto_1_Arqui.dir/main.cpp.o -c /home/carlos/CLionProjects/Proyecto_1_Arqui/main.cpp

CMakeFiles/Proyecto_1_Arqui.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto_1_Arqui.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carlos/CLionProjects/Proyecto_1_Arqui/main.cpp > CMakeFiles/Proyecto_1_Arqui.dir/main.cpp.i

CMakeFiles/Proyecto_1_Arqui.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto_1_Arqui.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carlos/CLionProjects/Proyecto_1_Arqui/main.cpp -o CMakeFiles/Proyecto_1_Arqui.dir/main.cpp.s

# Object files for target Proyecto_1_Arqui
Proyecto_1_Arqui_OBJECTS = \
"CMakeFiles/Proyecto_1_Arqui.dir/main.cpp.o"

# External object files for target Proyecto_1_Arqui
Proyecto_1_Arqui_EXTERNAL_OBJECTS =

Proyecto_1_Arqui: CMakeFiles/Proyecto_1_Arqui.dir/main.cpp.o
Proyecto_1_Arqui: CMakeFiles/Proyecto_1_Arqui.dir/build.make
Proyecto_1_Arqui: CMakeFiles/Proyecto_1_Arqui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/carlos/CLionProjects/Proyecto_1_Arqui/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Proyecto_1_Arqui"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Proyecto_1_Arqui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Proyecto_1_Arqui.dir/build: Proyecto_1_Arqui
.PHONY : CMakeFiles/Proyecto_1_Arqui.dir/build

CMakeFiles/Proyecto_1_Arqui.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Proyecto_1_Arqui.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Proyecto_1_Arqui.dir/clean

CMakeFiles/Proyecto_1_Arqui.dir/depend:
	cd /home/carlos/CLionProjects/Proyecto_1_Arqui/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/carlos/CLionProjects/Proyecto_1_Arqui /home/carlos/CLionProjects/Proyecto_1_Arqui /home/carlos/CLionProjects/Proyecto_1_Arqui/cmake-build-debug /home/carlos/CLionProjects/Proyecto_1_Arqui/cmake-build-debug /home/carlos/CLionProjects/Proyecto_1_Arqui/cmake-build-debug/CMakeFiles/Proyecto_1_Arqui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Proyecto_1_Arqui.dir/depend

