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
CMAKE_COMMAND = "C:/Program Files (x86)/Microsoft Visual Studio/2019/BuildTools/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files (x86)/Microsoft Visual Studio/2019/BuildTools/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:/Projects/Argparser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:/Projects/Argparser/build

# Include any dependencies generated for this target.
include argparser/CMakeFiles/argparser.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include argparser/CMakeFiles/argparser.dir/compiler_depend.make

# Include the progress variables for this target.
include argparser/CMakeFiles/argparser.dir/progress.make

# Include the compile flags for this target's objects.
include argparser/CMakeFiles/argparser.dir/flags.make

argparser/CMakeFiles/argparser.dir/src/argparser.cpp.obj: argparser/CMakeFiles/argparser.dir/flags.make
argparser/CMakeFiles/argparser.dir/src/argparser.cpp.obj: argparser/CMakeFiles/argparser.dir/includes_CXX.rsp
argparser/CMakeFiles/argparser.dir/src/argparser.cpp.obj: ../argparser/src/argparser.cpp
argparser/CMakeFiles/argparser.dir/src/argparser.cpp.obj: argparser/CMakeFiles/argparser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/Projects/Argparser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object argparser/CMakeFiles/argparser.dir/src/argparser.cpp.obj"
	cd D:/Projects/Argparser/build/argparser && C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT argparser/CMakeFiles/argparser.dir/src/argparser.cpp.obj -MF CMakeFiles/argparser.dir/src/argparser.cpp.obj.d -o CMakeFiles/argparser.dir/src/argparser.cpp.obj -c D:/Projects/Argparser/argparser/src/argparser.cpp

argparser/CMakeFiles/argparser.dir/src/argparser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/argparser.dir/src/argparser.cpp.i"
	cd D:/Projects/Argparser/build/argparser && C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/Projects/Argparser/argparser/src/argparser.cpp > CMakeFiles/argparser.dir/src/argparser.cpp.i

argparser/CMakeFiles/argparser.dir/src/argparser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/argparser.dir/src/argparser.cpp.s"
	cd D:/Projects/Argparser/build/argparser && C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/Projects/Argparser/argparser/src/argparser.cpp -o CMakeFiles/argparser.dir/src/argparser.cpp.s

argparser/CMakeFiles/argparser.dir/src/argument.cpp.obj: argparser/CMakeFiles/argparser.dir/flags.make
argparser/CMakeFiles/argparser.dir/src/argument.cpp.obj: argparser/CMakeFiles/argparser.dir/includes_CXX.rsp
argparser/CMakeFiles/argparser.dir/src/argument.cpp.obj: ../argparser/src/argument.cpp
argparser/CMakeFiles/argparser.dir/src/argument.cpp.obj: argparser/CMakeFiles/argparser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/Projects/Argparser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object argparser/CMakeFiles/argparser.dir/src/argument.cpp.obj"
	cd D:/Projects/Argparser/build/argparser && C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT argparser/CMakeFiles/argparser.dir/src/argument.cpp.obj -MF CMakeFiles/argparser.dir/src/argument.cpp.obj.d -o CMakeFiles/argparser.dir/src/argument.cpp.obj -c D:/Projects/Argparser/argparser/src/argument.cpp

argparser/CMakeFiles/argparser.dir/src/argument.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/argparser.dir/src/argument.cpp.i"
	cd D:/Projects/Argparser/build/argparser && C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/Projects/Argparser/argparser/src/argument.cpp > CMakeFiles/argparser.dir/src/argument.cpp.i

argparser/CMakeFiles/argparser.dir/src/argument.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/argparser.dir/src/argument.cpp.s"
	cd D:/Projects/Argparser/build/argparser && C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/Projects/Argparser/argparser/src/argument.cpp -o CMakeFiles/argparser.dir/src/argument.cpp.s

argparser/CMakeFiles/argparser.dir/src/argflag.cpp.obj: argparser/CMakeFiles/argparser.dir/flags.make
argparser/CMakeFiles/argparser.dir/src/argflag.cpp.obj: argparser/CMakeFiles/argparser.dir/includes_CXX.rsp
argparser/CMakeFiles/argparser.dir/src/argflag.cpp.obj: ../argparser/src/argflag.cpp
argparser/CMakeFiles/argparser.dir/src/argflag.cpp.obj: argparser/CMakeFiles/argparser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/Projects/Argparser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object argparser/CMakeFiles/argparser.dir/src/argflag.cpp.obj"
	cd D:/Projects/Argparser/build/argparser && C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT argparser/CMakeFiles/argparser.dir/src/argflag.cpp.obj -MF CMakeFiles/argparser.dir/src/argflag.cpp.obj.d -o CMakeFiles/argparser.dir/src/argflag.cpp.obj -c D:/Projects/Argparser/argparser/src/argflag.cpp

argparser/CMakeFiles/argparser.dir/src/argflag.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/argparser.dir/src/argflag.cpp.i"
	cd D:/Projects/Argparser/build/argparser && C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/Projects/Argparser/argparser/src/argflag.cpp > CMakeFiles/argparser.dir/src/argflag.cpp.i

argparser/CMakeFiles/argparser.dir/src/argflag.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/argparser.dir/src/argflag.cpp.s"
	cd D:/Projects/Argparser/build/argparser && C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/Projects/Argparser/argparser/src/argflag.cpp -o CMakeFiles/argparser.dir/src/argflag.cpp.s

argparser/CMakeFiles/argparser.dir/src/argint.cpp.obj: argparser/CMakeFiles/argparser.dir/flags.make
argparser/CMakeFiles/argparser.dir/src/argint.cpp.obj: argparser/CMakeFiles/argparser.dir/includes_CXX.rsp
argparser/CMakeFiles/argparser.dir/src/argint.cpp.obj: ../argparser/src/argint.cpp
argparser/CMakeFiles/argparser.dir/src/argint.cpp.obj: argparser/CMakeFiles/argparser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/Projects/Argparser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object argparser/CMakeFiles/argparser.dir/src/argint.cpp.obj"
	cd D:/Projects/Argparser/build/argparser && C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT argparser/CMakeFiles/argparser.dir/src/argint.cpp.obj -MF CMakeFiles/argparser.dir/src/argint.cpp.obj.d -o CMakeFiles/argparser.dir/src/argint.cpp.obj -c D:/Projects/Argparser/argparser/src/argint.cpp

argparser/CMakeFiles/argparser.dir/src/argint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/argparser.dir/src/argint.cpp.i"
	cd D:/Projects/Argparser/build/argparser && C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/Projects/Argparser/argparser/src/argint.cpp > CMakeFiles/argparser.dir/src/argint.cpp.i

argparser/CMakeFiles/argparser.dir/src/argint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/argparser.dir/src/argint.cpp.s"
	cd D:/Projects/Argparser/build/argparser && C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/Projects/Argparser/argparser/src/argint.cpp -o CMakeFiles/argparser.dir/src/argint.cpp.s

argparser/CMakeFiles/argparser.dir/src/argdouble.cpp.obj: argparser/CMakeFiles/argparser.dir/flags.make
argparser/CMakeFiles/argparser.dir/src/argdouble.cpp.obj: argparser/CMakeFiles/argparser.dir/includes_CXX.rsp
argparser/CMakeFiles/argparser.dir/src/argdouble.cpp.obj: ../argparser/src/argdouble.cpp
argparser/CMakeFiles/argparser.dir/src/argdouble.cpp.obj: argparser/CMakeFiles/argparser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/Projects/Argparser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object argparser/CMakeFiles/argparser.dir/src/argdouble.cpp.obj"
	cd D:/Projects/Argparser/build/argparser && C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT argparser/CMakeFiles/argparser.dir/src/argdouble.cpp.obj -MF CMakeFiles/argparser.dir/src/argdouble.cpp.obj.d -o CMakeFiles/argparser.dir/src/argdouble.cpp.obj -c D:/Projects/Argparser/argparser/src/argdouble.cpp

argparser/CMakeFiles/argparser.dir/src/argdouble.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/argparser.dir/src/argdouble.cpp.i"
	cd D:/Projects/Argparser/build/argparser && C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/Projects/Argparser/argparser/src/argdouble.cpp > CMakeFiles/argparser.dir/src/argdouble.cpp.i

argparser/CMakeFiles/argparser.dir/src/argdouble.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/argparser.dir/src/argdouble.cpp.s"
	cd D:/Projects/Argparser/build/argparser && C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/Projects/Argparser/argparser/src/argdouble.cpp -o CMakeFiles/argparser.dir/src/argdouble.cpp.s

argparser/CMakeFiles/argparser.dir/src/argstring.cpp.obj: argparser/CMakeFiles/argparser.dir/flags.make
argparser/CMakeFiles/argparser.dir/src/argstring.cpp.obj: argparser/CMakeFiles/argparser.dir/includes_CXX.rsp
argparser/CMakeFiles/argparser.dir/src/argstring.cpp.obj: ../argparser/src/argstring.cpp
argparser/CMakeFiles/argparser.dir/src/argstring.cpp.obj: argparser/CMakeFiles/argparser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/Projects/Argparser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object argparser/CMakeFiles/argparser.dir/src/argstring.cpp.obj"
	cd D:/Projects/Argparser/build/argparser && C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT argparser/CMakeFiles/argparser.dir/src/argstring.cpp.obj -MF CMakeFiles/argparser.dir/src/argstring.cpp.obj.d -o CMakeFiles/argparser.dir/src/argstring.cpp.obj -c D:/Projects/Argparser/argparser/src/argstring.cpp

argparser/CMakeFiles/argparser.dir/src/argstring.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/argparser.dir/src/argstring.cpp.i"
	cd D:/Projects/Argparser/build/argparser && C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/Projects/Argparser/argparser/src/argstring.cpp > CMakeFiles/argparser.dir/src/argstring.cpp.i

argparser/CMakeFiles/argparser.dir/src/argstring.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/argparser.dir/src/argstring.cpp.s"
	cd D:/Projects/Argparser/build/argparser && C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/Projects/Argparser/argparser/src/argstring.cpp -o CMakeFiles/argparser.dir/src/argstring.cpp.s

# Object files for target argparser
argparser_OBJECTS = \
"CMakeFiles/argparser.dir/src/argparser.cpp.obj" \
"CMakeFiles/argparser.dir/src/argument.cpp.obj" \
"CMakeFiles/argparser.dir/src/argflag.cpp.obj" \
"CMakeFiles/argparser.dir/src/argint.cpp.obj" \
"CMakeFiles/argparser.dir/src/argdouble.cpp.obj" \
"CMakeFiles/argparser.dir/src/argstring.cpp.obj"

# External object files for target argparser
argparser_EXTERNAL_OBJECTS =

argparser/libargparser.a: argparser/CMakeFiles/argparser.dir/src/argparser.cpp.obj
argparser/libargparser.a: argparser/CMakeFiles/argparser.dir/src/argument.cpp.obj
argparser/libargparser.a: argparser/CMakeFiles/argparser.dir/src/argflag.cpp.obj
argparser/libargparser.a: argparser/CMakeFiles/argparser.dir/src/argint.cpp.obj
argparser/libargparser.a: argparser/CMakeFiles/argparser.dir/src/argdouble.cpp.obj
argparser/libargparser.a: argparser/CMakeFiles/argparser.dir/src/argstring.cpp.obj
argparser/libargparser.a: argparser/CMakeFiles/argparser.dir/build.make
argparser/libargparser.a: argparser/CMakeFiles/argparser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:/Projects/Argparser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libargparser.a"
	cd D:/Projects/Argparser/build/argparser && $(CMAKE_COMMAND) -P CMakeFiles/argparser.dir/cmake_clean_target.cmake
	cd D:/Projects/Argparser/build/argparser && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/argparser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
argparser/CMakeFiles/argparser.dir/build: argparser/libargparser.a
.PHONY : argparser/CMakeFiles/argparser.dir/build

argparser/CMakeFiles/argparser.dir/clean:
	cd D:/Projects/Argparser/build/argparser && $(CMAKE_COMMAND) -P CMakeFiles/argparser.dir/cmake_clean.cmake
.PHONY : argparser/CMakeFiles/argparser.dir/clean

argparser/CMakeFiles/argparser.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/Projects/Argparser D:/Projects/Argparser/argparser D:/Projects/Argparser/build D:/Projects/Argparser/build/argparser D:/Projects/Argparser/build/argparser/CMakeFiles/argparser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : argparser/CMakeFiles/argparser.dir/depend
