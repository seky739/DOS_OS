# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\micha\CLionProjects\OS_proj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\micha\CLionProjects\OS_proj\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OS_proj.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OS_proj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OS_proj.dir/flags.make

CMakeFiles/OS_proj.dir/main.cpp.obj: CMakeFiles/OS_proj.dir/flags.make
CMakeFiles/OS_proj.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\micha\CLionProjects\OS_proj\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OS_proj.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OS_proj.dir\main.cpp.obj -c C:\Users\micha\CLionProjects\OS_proj\main.cpp

CMakeFiles/OS_proj.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OS_proj.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\micha\CLionProjects\OS_proj\main.cpp > CMakeFiles\OS_proj.dir\main.cpp.i

CMakeFiles/OS_proj.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OS_proj.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\micha\CLionProjects\OS_proj\main.cpp -o CMakeFiles\OS_proj.dir\main.cpp.s

CMakeFiles/OS_proj.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/OS_proj.dir/main.cpp.obj.requires

CMakeFiles/OS_proj.dir/main.cpp.obj.provides: CMakeFiles/OS_proj.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OS_proj.dir\build.make CMakeFiles/OS_proj.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/OS_proj.dir/main.cpp.obj.provides

CMakeFiles/OS_proj.dir/main.cpp.obj.provides.build: CMakeFiles/OS_proj.dir/main.cpp.obj


CMakeFiles/OS_proj.dir/Opfunction.cpp.obj: CMakeFiles/OS_proj.dir/flags.make
CMakeFiles/OS_proj.dir/Opfunction.cpp.obj: ../Opfunction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\micha\CLionProjects\OS_proj\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OS_proj.dir/Opfunction.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OS_proj.dir\Opfunction.cpp.obj -c C:\Users\micha\CLionProjects\OS_proj\Opfunction.cpp

CMakeFiles/OS_proj.dir/Opfunction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OS_proj.dir/Opfunction.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\micha\CLionProjects\OS_proj\Opfunction.cpp > CMakeFiles\OS_proj.dir\Opfunction.cpp.i

CMakeFiles/OS_proj.dir/Opfunction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OS_proj.dir/Opfunction.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\micha\CLionProjects\OS_proj\Opfunction.cpp -o CMakeFiles\OS_proj.dir\Opfunction.cpp.s

CMakeFiles/OS_proj.dir/Opfunction.cpp.obj.requires:

.PHONY : CMakeFiles/OS_proj.dir/Opfunction.cpp.obj.requires

CMakeFiles/OS_proj.dir/Opfunction.cpp.obj.provides: CMakeFiles/OS_proj.dir/Opfunction.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OS_proj.dir\build.make CMakeFiles/OS_proj.dir/Opfunction.cpp.obj.provides.build
.PHONY : CMakeFiles/OS_proj.dir/Opfunction.cpp.obj.provides

CMakeFiles/OS_proj.dir/Opfunction.cpp.obj.provides.build: CMakeFiles/OS_proj.dir/Opfunction.cpp.obj


CMakeFiles/OS_proj.dir/CPU.cpp.obj: CMakeFiles/OS_proj.dir/flags.make
CMakeFiles/OS_proj.dir/CPU.cpp.obj: ../CPU.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\micha\CLionProjects\OS_proj\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OS_proj.dir/CPU.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OS_proj.dir\CPU.cpp.obj -c C:\Users\micha\CLionProjects\OS_proj\CPU.cpp

CMakeFiles/OS_proj.dir/CPU.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OS_proj.dir/CPU.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\micha\CLionProjects\OS_proj\CPU.cpp > CMakeFiles\OS_proj.dir\CPU.cpp.i

CMakeFiles/OS_proj.dir/CPU.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OS_proj.dir/CPU.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\micha\CLionProjects\OS_proj\CPU.cpp -o CMakeFiles\OS_proj.dir\CPU.cpp.s

CMakeFiles/OS_proj.dir/CPU.cpp.obj.requires:

.PHONY : CMakeFiles/OS_proj.dir/CPU.cpp.obj.requires

CMakeFiles/OS_proj.dir/CPU.cpp.obj.provides: CMakeFiles/OS_proj.dir/CPU.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OS_proj.dir\build.make CMakeFiles/OS_proj.dir/CPU.cpp.obj.provides.build
.PHONY : CMakeFiles/OS_proj.dir/CPU.cpp.obj.provides

CMakeFiles/OS_proj.dir/CPU.cpp.obj.provides.build: CMakeFiles/OS_proj.dir/CPU.cpp.obj


# Object files for target OS_proj
OS_proj_OBJECTS = \
"CMakeFiles/OS_proj.dir/main.cpp.obj" \
"CMakeFiles/OS_proj.dir/Opfunction.cpp.obj" \
"CMakeFiles/OS_proj.dir/CPU.cpp.obj"

# External object files for target OS_proj
OS_proj_EXTERNAL_OBJECTS =

OS_proj.exe: CMakeFiles/OS_proj.dir/main.cpp.obj
OS_proj.exe: CMakeFiles/OS_proj.dir/Opfunction.cpp.obj
OS_proj.exe: CMakeFiles/OS_proj.dir/CPU.cpp.obj
OS_proj.exe: CMakeFiles/OS_proj.dir/build.make
OS_proj.exe: CMakeFiles/OS_proj.dir/linklibs.rsp
OS_proj.exe: CMakeFiles/OS_proj.dir/objects1.rsp
OS_proj.exe: CMakeFiles/OS_proj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\micha\CLionProjects\OS_proj\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable OS_proj.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\OS_proj.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OS_proj.dir/build: OS_proj.exe

.PHONY : CMakeFiles/OS_proj.dir/build

CMakeFiles/OS_proj.dir/requires: CMakeFiles/OS_proj.dir/main.cpp.obj.requires
CMakeFiles/OS_proj.dir/requires: CMakeFiles/OS_proj.dir/Opfunction.cpp.obj.requires
CMakeFiles/OS_proj.dir/requires: CMakeFiles/OS_proj.dir/CPU.cpp.obj.requires

.PHONY : CMakeFiles/OS_proj.dir/requires

CMakeFiles/OS_proj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\OS_proj.dir\cmake_clean.cmake
.PHONY : CMakeFiles/OS_proj.dir/clean

CMakeFiles/OS_proj.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\micha\CLionProjects\OS_proj C:\Users\micha\CLionProjects\OS_proj C:\Users\micha\CLionProjects\OS_proj\cmake-build-debug C:\Users\micha\CLionProjects\OS_proj\cmake-build-debug C:\Users\micha\CLionProjects\OS_proj\cmake-build-debug\CMakeFiles\OS_proj.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OS_proj.dir/depend

