# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ysalata/CLionProjects/fdf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ysalata/CLionProjects/fdf/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/fdf_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fdf_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fdf_test.dir/flags.make

CMakeFiles/fdf_test.dir/main.c.o: CMakeFiles/fdf_test.dir/flags.make
CMakeFiles/fdf_test.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ysalata/CLionProjects/fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/fdf_test.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fdf_test.dir/main.c.o   -c /Users/ysalata/CLionProjects/fdf/main.c

CMakeFiles/fdf_test.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fdf_test.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ysalata/CLionProjects/fdf/main.c > CMakeFiles/fdf_test.dir/main.c.i

CMakeFiles/fdf_test.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fdf_test.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ysalata/CLionProjects/fdf/main.c -o CMakeFiles/fdf_test.dir/main.c.s

CMakeFiles/fdf_test.dir/main.c.o.requires:

.PHONY : CMakeFiles/fdf_test.dir/main.c.o.requires

CMakeFiles/fdf_test.dir/main.c.o.provides: CMakeFiles/fdf_test.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/fdf_test.dir/build.make CMakeFiles/fdf_test.dir/main.c.o.provides.build
.PHONY : CMakeFiles/fdf_test.dir/main.c.o.provides

CMakeFiles/fdf_test.dir/main.c.o.provides.build: CMakeFiles/fdf_test.dir/main.c.o


CMakeFiles/fdf_test.dir/parsing.c.o: CMakeFiles/fdf_test.dir/flags.make
CMakeFiles/fdf_test.dir/parsing.c.o: ../parsing.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ysalata/CLionProjects/fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/fdf_test.dir/parsing.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fdf_test.dir/parsing.c.o   -c /Users/ysalata/CLionProjects/fdf/parsing.c

CMakeFiles/fdf_test.dir/parsing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fdf_test.dir/parsing.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ysalata/CLionProjects/fdf/parsing.c > CMakeFiles/fdf_test.dir/parsing.c.i

CMakeFiles/fdf_test.dir/parsing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fdf_test.dir/parsing.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ysalata/CLionProjects/fdf/parsing.c -o CMakeFiles/fdf_test.dir/parsing.c.s

CMakeFiles/fdf_test.dir/parsing.c.o.requires:

.PHONY : CMakeFiles/fdf_test.dir/parsing.c.o.requires

CMakeFiles/fdf_test.dir/parsing.c.o.provides: CMakeFiles/fdf_test.dir/parsing.c.o.requires
	$(MAKE) -f CMakeFiles/fdf_test.dir/build.make CMakeFiles/fdf_test.dir/parsing.c.o.provides.build
.PHONY : CMakeFiles/fdf_test.dir/parsing.c.o.provides

CMakeFiles/fdf_test.dir/parsing.c.o.provides.build: CMakeFiles/fdf_test.dir/parsing.c.o


CMakeFiles/fdf_test.dir/algo.c.o: CMakeFiles/fdf_test.dir/flags.make
CMakeFiles/fdf_test.dir/algo.c.o: ../algo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ysalata/CLionProjects/fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/fdf_test.dir/algo.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fdf_test.dir/algo.c.o   -c /Users/ysalata/CLionProjects/fdf/algo.c

CMakeFiles/fdf_test.dir/algo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fdf_test.dir/algo.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ysalata/CLionProjects/fdf/algo.c > CMakeFiles/fdf_test.dir/algo.c.i

CMakeFiles/fdf_test.dir/algo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fdf_test.dir/algo.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ysalata/CLionProjects/fdf/algo.c -o CMakeFiles/fdf_test.dir/algo.c.s

CMakeFiles/fdf_test.dir/algo.c.o.requires:

.PHONY : CMakeFiles/fdf_test.dir/algo.c.o.requires

CMakeFiles/fdf_test.dir/algo.c.o.provides: CMakeFiles/fdf_test.dir/algo.c.o.requires
	$(MAKE) -f CMakeFiles/fdf_test.dir/build.make CMakeFiles/fdf_test.dir/algo.c.o.provides.build
.PHONY : CMakeFiles/fdf_test.dir/algo.c.o.provides

CMakeFiles/fdf_test.dir/algo.c.o.provides.build: CMakeFiles/fdf_test.dir/algo.c.o


CMakeFiles/fdf_test.dir/drawmap.c.o: CMakeFiles/fdf_test.dir/flags.make
CMakeFiles/fdf_test.dir/drawmap.c.o: ../drawmap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ysalata/CLionProjects/fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/fdf_test.dir/drawmap.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fdf_test.dir/drawmap.c.o   -c /Users/ysalata/CLionProjects/fdf/drawmap.c

CMakeFiles/fdf_test.dir/drawmap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fdf_test.dir/drawmap.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ysalata/CLionProjects/fdf/drawmap.c > CMakeFiles/fdf_test.dir/drawmap.c.i

CMakeFiles/fdf_test.dir/drawmap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fdf_test.dir/drawmap.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ysalata/CLionProjects/fdf/drawmap.c -o CMakeFiles/fdf_test.dir/drawmap.c.s

CMakeFiles/fdf_test.dir/drawmap.c.o.requires:

.PHONY : CMakeFiles/fdf_test.dir/drawmap.c.o.requires

CMakeFiles/fdf_test.dir/drawmap.c.o.provides: CMakeFiles/fdf_test.dir/drawmap.c.o.requires
	$(MAKE) -f CMakeFiles/fdf_test.dir/build.make CMakeFiles/fdf_test.dir/drawmap.c.o.provides.build
.PHONY : CMakeFiles/fdf_test.dir/drawmap.c.o.provides

CMakeFiles/fdf_test.dir/drawmap.c.o.provides.build: CMakeFiles/fdf_test.dir/drawmap.c.o


CMakeFiles/fdf_test.dir/onaction.c.o: CMakeFiles/fdf_test.dir/flags.make
CMakeFiles/fdf_test.dir/onaction.c.o: ../onaction.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ysalata/CLionProjects/fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/fdf_test.dir/onaction.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fdf_test.dir/onaction.c.o   -c /Users/ysalata/CLionProjects/fdf/onaction.c

CMakeFiles/fdf_test.dir/onaction.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fdf_test.dir/onaction.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ysalata/CLionProjects/fdf/onaction.c > CMakeFiles/fdf_test.dir/onaction.c.i

CMakeFiles/fdf_test.dir/onaction.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fdf_test.dir/onaction.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ysalata/CLionProjects/fdf/onaction.c -o CMakeFiles/fdf_test.dir/onaction.c.s

CMakeFiles/fdf_test.dir/onaction.c.o.requires:

.PHONY : CMakeFiles/fdf_test.dir/onaction.c.o.requires

CMakeFiles/fdf_test.dir/onaction.c.o.provides: CMakeFiles/fdf_test.dir/onaction.c.o.requires
	$(MAKE) -f CMakeFiles/fdf_test.dir/build.make CMakeFiles/fdf_test.dir/onaction.c.o.provides.build
.PHONY : CMakeFiles/fdf_test.dir/onaction.c.o.provides

CMakeFiles/fdf_test.dir/onaction.c.o.provides.build: CMakeFiles/fdf_test.dir/onaction.c.o


CMakeFiles/fdf_test.dir/recalculating.c.o: CMakeFiles/fdf_test.dir/flags.make
CMakeFiles/fdf_test.dir/recalculating.c.o: ../recalculating.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ysalata/CLionProjects/fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/fdf_test.dir/recalculating.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fdf_test.dir/recalculating.c.o   -c /Users/ysalata/CLionProjects/fdf/recalculating.c

CMakeFiles/fdf_test.dir/recalculating.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fdf_test.dir/recalculating.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ysalata/CLionProjects/fdf/recalculating.c > CMakeFiles/fdf_test.dir/recalculating.c.i

CMakeFiles/fdf_test.dir/recalculating.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fdf_test.dir/recalculating.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ysalata/CLionProjects/fdf/recalculating.c -o CMakeFiles/fdf_test.dir/recalculating.c.s

CMakeFiles/fdf_test.dir/recalculating.c.o.requires:

.PHONY : CMakeFiles/fdf_test.dir/recalculating.c.o.requires

CMakeFiles/fdf_test.dir/recalculating.c.o.provides: CMakeFiles/fdf_test.dir/recalculating.c.o.requires
	$(MAKE) -f CMakeFiles/fdf_test.dir/build.make CMakeFiles/fdf_test.dir/recalculating.c.o.provides.build
.PHONY : CMakeFiles/fdf_test.dir/recalculating.c.o.provides

CMakeFiles/fdf_test.dir/recalculating.c.o.provides.build: CMakeFiles/fdf_test.dir/recalculating.c.o


# Object files for target fdf_test
fdf_test_OBJECTS = \
"CMakeFiles/fdf_test.dir/main.c.o" \
"CMakeFiles/fdf_test.dir/parsing.c.o" \
"CMakeFiles/fdf_test.dir/algo.c.o" \
"CMakeFiles/fdf_test.dir/drawmap.c.o" \
"CMakeFiles/fdf_test.dir/onaction.c.o" \
"CMakeFiles/fdf_test.dir/recalculating.c.o"

# External object files for target fdf_test
fdf_test_EXTERNAL_OBJECTS =

fdf_test: CMakeFiles/fdf_test.dir/main.c.o
fdf_test: CMakeFiles/fdf_test.dir/parsing.c.o
fdf_test: CMakeFiles/fdf_test.dir/algo.c.o
fdf_test: CMakeFiles/fdf_test.dir/drawmap.c.o
fdf_test: CMakeFiles/fdf_test.dir/onaction.c.o
fdf_test: CMakeFiles/fdf_test.dir/recalculating.c.o
fdf_test: CMakeFiles/fdf_test.dir/build.make
fdf_test: ../libft/libft.a
fdf_test: ../minilibx/libmlx.a
fdf_test: CMakeFiles/fdf_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ysalata/CLionProjects/fdf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable fdf_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fdf_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fdf_test.dir/build: fdf_test

.PHONY : CMakeFiles/fdf_test.dir/build

CMakeFiles/fdf_test.dir/requires: CMakeFiles/fdf_test.dir/main.c.o.requires
CMakeFiles/fdf_test.dir/requires: CMakeFiles/fdf_test.dir/parsing.c.o.requires
CMakeFiles/fdf_test.dir/requires: CMakeFiles/fdf_test.dir/algo.c.o.requires
CMakeFiles/fdf_test.dir/requires: CMakeFiles/fdf_test.dir/drawmap.c.o.requires
CMakeFiles/fdf_test.dir/requires: CMakeFiles/fdf_test.dir/onaction.c.o.requires
CMakeFiles/fdf_test.dir/requires: CMakeFiles/fdf_test.dir/recalculating.c.o.requires

.PHONY : CMakeFiles/fdf_test.dir/requires

CMakeFiles/fdf_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fdf_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fdf_test.dir/clean

CMakeFiles/fdf_test.dir/depend:
	cd /Users/ysalata/CLionProjects/fdf/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ysalata/CLionProjects/fdf /Users/ysalata/CLionProjects/fdf /Users/ysalata/CLionProjects/fdf/cmake-build-debug /Users/ysalata/CLionProjects/fdf/cmake-build-debug /Users/ysalata/CLionProjects/fdf/cmake-build-debug/CMakeFiles/fdf_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fdf_test.dir/depend

