# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 2\cmake-build-debug-mingw"

# Include any dependencies generated for this target.
include CMakeFiles/zadanie_2_RB.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zadanie_2_RB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zadanie_2_RB.dir/flags.make

CMakeFiles/zadanie_2_RB.dir/zadanie2_RB.c.obj: CMakeFiles/zadanie_2_RB.dir/flags.make
CMakeFiles/zadanie_2_RB.dir/zadanie2_RB.c.obj: ../zadanie2_RB.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 2\cmake-build-debug-mingw\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/zadanie_2_RB.dir/zadanie2_RB.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\zadanie_2_RB.dir\zadanie2_RB.c.obj   -c "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 2\zadanie2_RB.c"

CMakeFiles/zadanie_2_RB.dir/zadanie2_RB.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zadanie_2_RB.dir/zadanie2_RB.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 2\zadanie2_RB.c" > CMakeFiles\zadanie_2_RB.dir\zadanie2_RB.c.i

CMakeFiles/zadanie_2_RB.dir/zadanie2_RB.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zadanie_2_RB.dir/zadanie2_RB.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 2\zadanie2_RB.c" -o CMakeFiles\zadanie_2_RB.dir\zadanie2_RB.c.s

# Object files for target zadanie_2_RB
zadanie_2_RB_OBJECTS = \
"CMakeFiles/zadanie_2_RB.dir/zadanie2_RB.c.obj"

# External object files for target zadanie_2_RB
zadanie_2_RB_EXTERNAL_OBJECTS =

zadanie_2_RB.exe: CMakeFiles/zadanie_2_RB.dir/zadanie2_RB.c.obj
zadanie_2_RB.exe: CMakeFiles/zadanie_2_RB.dir/build.make
zadanie_2_RB.exe: CMakeFiles/zadanie_2_RB.dir/linklibs.rsp
zadanie_2_RB.exe: CMakeFiles/zadanie_2_RB.dir/objects1.rsp
zadanie_2_RB.exe: CMakeFiles/zadanie_2_RB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 2\cmake-build-debug-mingw\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable zadanie_2_RB.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\zadanie_2_RB.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zadanie_2_RB.dir/build: zadanie_2_RB.exe

.PHONY : CMakeFiles/zadanie_2_RB.dir/build

CMakeFiles/zadanie_2_RB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\zadanie_2_RB.dir\cmake_clean.cmake
.PHONY : CMakeFiles/zadanie_2_RB.dir/clean

CMakeFiles/zadanie_2_RB.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 2" "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 2" "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 2\cmake-build-debug-mingw" "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 2\cmake-build-debug-mingw" "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 2\cmake-build-debug-mingw\CMakeFiles\zadanie_2_RB.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/zadanie_2_RB.dir/depend
