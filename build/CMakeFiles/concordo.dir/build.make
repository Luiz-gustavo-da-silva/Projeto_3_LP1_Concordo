# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/luiz/Área de Trabalho/Projeto_3_LP1_Concordo"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/luiz/Área de Trabalho/Projeto_3_LP1_Concordo/build"

# Include any dependencies generated for this target.
include CMakeFiles/concordo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/concordo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/concordo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/concordo.dir/flags.make

CMakeFiles/concordo.dir/main.cpp.o: CMakeFiles/concordo.dir/flags.make
CMakeFiles/concordo.dir/main.cpp.o: ../main.cpp
CMakeFiles/concordo.dir/main.cpp.o: CMakeFiles/concordo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/luiz/Área de Trabalho/Projeto_3_LP1_Concordo/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/concordo.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/concordo.dir/main.cpp.o -MF CMakeFiles/concordo.dir/main.cpp.o.d -o CMakeFiles/concordo.dir/main.cpp.o -c "/home/luiz/Área de Trabalho/Projeto_3_LP1_Concordo/main.cpp"

CMakeFiles/concordo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/concordo.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/luiz/Área de Trabalho/Projeto_3_LP1_Concordo/main.cpp" > CMakeFiles/concordo.dir/main.cpp.i

CMakeFiles/concordo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/concordo.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/luiz/Área de Trabalho/Projeto_3_LP1_Concordo/main.cpp" -o CMakeFiles/concordo.dir/main.cpp.s

# Object files for target concordo
concordo_OBJECTS = \
"CMakeFiles/concordo.dir/main.cpp.o"

# External object files for target concordo
concordo_EXTERNAL_OBJECTS =

concordo: CMakeFiles/concordo.dir/main.cpp.o
concordo: CMakeFiles/concordo.dir/build.make
concordo: CMakeFiles/concordo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/luiz/Área de Trabalho/Projeto_3_LP1_Concordo/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable concordo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/concordo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/concordo.dir/build: concordo
.PHONY : CMakeFiles/concordo.dir/build

CMakeFiles/concordo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/concordo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/concordo.dir/clean

CMakeFiles/concordo.dir/depend:
	cd "/home/luiz/Área de Trabalho/Projeto_3_LP1_Concordo/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/luiz/Área de Trabalho/Projeto_3_LP1_Concordo" "/home/luiz/Área de Trabalho/Projeto_3_LP1_Concordo" "/home/luiz/Área de Trabalho/Projeto_3_LP1_Concordo/build" "/home/luiz/Área de Trabalho/Projeto_3_LP1_Concordo/build" "/home/luiz/Área de Trabalho/Projeto_3_LP1_Concordo/build/CMakeFiles/concordo.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/concordo.dir/depend
