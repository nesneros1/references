# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/connor/calculator-project/1_SimpleCalc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/connor/calculator-project/1_SimpleCalc/build

# Include any dependencies generated for this target.
include CMakeFiles/simplecalc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simplecalc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simplecalc.dir/flags.make

CMakeFiles/simplecalc.dir/src/main.c.o: CMakeFiles/simplecalc.dir/flags.make
CMakeFiles/simplecalc.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/connor/calculator-project/1_SimpleCalc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/simplecalc.dir/src/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simplecalc.dir/src/main.c.o   -c /home/connor/calculator-project/1_SimpleCalc/src/main.c

CMakeFiles/simplecalc.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simplecalc.dir/src/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/connor/calculator-project/1_SimpleCalc/src/main.c > CMakeFiles/simplecalc.dir/src/main.c.i

CMakeFiles/simplecalc.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simplecalc.dir/src/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/connor/calculator-project/1_SimpleCalc/src/main.c -o CMakeFiles/simplecalc.dir/src/main.c.s

CMakeFiles/simplecalc.dir/src/operations.c.o: CMakeFiles/simplecalc.dir/flags.make
CMakeFiles/simplecalc.dir/src/operations.c.o: ../src/operations.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/connor/calculator-project/1_SimpleCalc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/simplecalc.dir/src/operations.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simplecalc.dir/src/operations.c.o   -c /home/connor/calculator-project/1_SimpleCalc/src/operations.c

CMakeFiles/simplecalc.dir/src/operations.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simplecalc.dir/src/operations.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/connor/calculator-project/1_SimpleCalc/src/operations.c > CMakeFiles/simplecalc.dir/src/operations.c.i

CMakeFiles/simplecalc.dir/src/operations.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simplecalc.dir/src/operations.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/connor/calculator-project/1_SimpleCalc/src/operations.c -o CMakeFiles/simplecalc.dir/src/operations.c.s

# Object files for target simplecalc
simplecalc_OBJECTS = \
"CMakeFiles/simplecalc.dir/src/main.c.o" \
"CMakeFiles/simplecalc.dir/src/operations.c.o"

# External object files for target simplecalc
simplecalc_EXTERNAL_OBJECTS =

simplecalc: CMakeFiles/simplecalc.dir/src/main.c.o
simplecalc: CMakeFiles/simplecalc.dir/src/operations.c.o
simplecalc: CMakeFiles/simplecalc.dir/build.make
simplecalc: CMakeFiles/simplecalc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/connor/calculator-project/1_SimpleCalc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable simplecalc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simplecalc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simplecalc.dir/build: simplecalc

.PHONY : CMakeFiles/simplecalc.dir/build

CMakeFiles/simplecalc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simplecalc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simplecalc.dir/clean

CMakeFiles/simplecalc.dir/depend:
	cd /home/connor/calculator-project/1_SimpleCalc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/connor/calculator-project/1_SimpleCalc /home/connor/calculator-project/1_SimpleCalc /home/connor/calculator-project/1_SimpleCalc/build /home/connor/calculator-project/1_SimpleCalc/build /home/connor/calculator-project/1_SimpleCalc/build/CMakeFiles/simplecalc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simplecalc.dir/depend

