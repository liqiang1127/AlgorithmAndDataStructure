# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2017.3.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2017.3.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\develop\workspace\Cworkspace\mukewang\MiniSpanTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\develop\workspace\Cworkspace\mukewang\MiniSpanTree\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MiniSpanTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MiniSpanTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MiniSpanTree.dir/flags.make

CMakeFiles/MiniSpanTree.dir/main.cpp.obj: CMakeFiles/MiniSpanTree.dir/flags.make
CMakeFiles/MiniSpanTree.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\develop\workspace\Cworkspace\mukewang\MiniSpanTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MiniSpanTree.dir/main.cpp.obj"
	D:\mingw\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\MiniSpanTree.dir\main.cpp.obj -c D:\develop\workspace\Cworkspace\mukewang\MiniSpanTree\main.cpp

CMakeFiles/MiniSpanTree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MiniSpanTree.dir/main.cpp.i"
	D:\mingw\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\develop\workspace\Cworkspace\mukewang\MiniSpanTree\main.cpp > CMakeFiles\MiniSpanTree.dir\main.cpp.i

CMakeFiles/MiniSpanTree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MiniSpanTree.dir/main.cpp.s"
	D:\mingw\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\develop\workspace\Cworkspace\mukewang\MiniSpanTree\main.cpp -o CMakeFiles\MiniSpanTree.dir\main.cpp.s

CMakeFiles/MiniSpanTree.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/MiniSpanTree.dir/main.cpp.obj.requires

CMakeFiles/MiniSpanTree.dir/main.cpp.obj.provides: CMakeFiles/MiniSpanTree.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\MiniSpanTree.dir\build.make CMakeFiles/MiniSpanTree.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/MiniSpanTree.dir/main.cpp.obj.provides

CMakeFiles/MiniSpanTree.dir/main.cpp.obj.provides.build: CMakeFiles/MiniSpanTree.dir/main.cpp.obj


# Object files for target MiniSpanTree
MiniSpanTree_OBJECTS = \
"CMakeFiles/MiniSpanTree.dir/main.cpp.obj"

# External object files for target MiniSpanTree
MiniSpanTree_EXTERNAL_OBJECTS =

MiniSpanTree.exe: CMakeFiles/MiniSpanTree.dir/main.cpp.obj
MiniSpanTree.exe: CMakeFiles/MiniSpanTree.dir/build.make
MiniSpanTree.exe: CMakeFiles/MiniSpanTree.dir/linklibs.rsp
MiniSpanTree.exe: CMakeFiles/MiniSpanTree.dir/objects1.rsp
MiniSpanTree.exe: CMakeFiles/MiniSpanTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\develop\workspace\Cworkspace\mukewang\MiniSpanTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MiniSpanTree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MiniSpanTree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MiniSpanTree.dir/build: MiniSpanTree.exe

.PHONY : CMakeFiles/MiniSpanTree.dir/build

CMakeFiles/MiniSpanTree.dir/requires: CMakeFiles/MiniSpanTree.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/MiniSpanTree.dir/requires

CMakeFiles/MiniSpanTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MiniSpanTree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MiniSpanTree.dir/clean

CMakeFiles/MiniSpanTree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\develop\workspace\Cworkspace\mukewang\MiniSpanTree D:\develop\workspace\Cworkspace\mukewang\MiniSpanTree D:\develop\workspace\Cworkspace\mukewang\MiniSpanTree\cmake-build-debug D:\develop\workspace\Cworkspace\mukewang\MiniSpanTree\cmake-build-debug D:\develop\workspace\Cworkspace\mukewang\MiniSpanTree\cmake-build-debug\CMakeFiles\MiniSpanTree.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MiniSpanTree.dir/depend

