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
CMAKE_SOURCE_DIR = "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 3\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/zadanie_3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zadanie_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zadanie_3.dir/flags.make

CMakeFiles/zadanie_3.dir/main.c.obj: CMakeFiles/zadanie_3.dir/flags.make
CMakeFiles/zadanie_3.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/zadanie_3.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\zadanie_3.dir\main.c.obj   -c "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 3\main.c"

CMakeFiles/zadanie_3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zadanie_3.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 3\main.c" > CMakeFiles\zadanie_3.dir\main.c.i

CMakeFiles/zadanie_3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zadanie_3.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 3\main.c" -o CMakeFiles\zadanie_3.dir\main.c.s

# Object files for target zadanie_3
zadanie_3_OBJECTS = \
"CMakeFiles/zadanie_3.dir/main.c.obj"

# External object files for target zadanie_3
zadanie_3_EXTERNAL_OBJECTS =

zadanie_3.exe: CMakeFiles/zadanie_3.dir/main.c.obj
zadanie_3.exe: CMakeFiles/zadanie_3.dir/build.make
zadanie_3.exe: CMakeFiles/zadanie_3.dir/linklibs.rsp
zadanie_3.exe: CMakeFiles/zadanie_3.dir/objects1.rsp
zadanie_3.exe: CMakeFiles/zadanie_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 3\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable zadanie_3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\zadanie_3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zadanie_3.dir/build: zadanie_3.exe

.PHONY : CMakeFiles/zadanie_3.dir/build

CMakeFiles/zadanie_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\zadanie_3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/zadanie_3.dir/clean

CMakeFiles/zadanie_3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 3" "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 3" "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 3\cmake-build-debug" "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 3\cmake-build-debug" "C:\Users\samue\Desktop\Skola\4. Semester\DSA\zadanie 3\cmake-build-debug\CMakeFiles\zadanie_3.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/zadanie_3.dir/depend
