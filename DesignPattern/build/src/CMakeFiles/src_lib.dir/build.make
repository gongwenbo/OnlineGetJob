# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /shared/cmake-3.13.0-rc1-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /shared/cmake-3.13.0-rc1-Linux-x86_64/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /shared/OnlineGetJob/DesignPattern

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /shared/OnlineGetJob/DesignPattern/build

# Include any dependencies generated for this target.
include src/CMakeFiles/src_lib.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/src_lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/src_lib.dir/flags.make

src/CMakeFiles/src_lib.dir/abs_factory.cpp.o: src/CMakeFiles/src_lib.dir/flags.make
src/CMakeFiles/src_lib.dir/abs_factory.cpp.o: ../src/abs_factory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/shared/OnlineGetJob/DesignPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/src_lib.dir/abs_factory.cpp.o"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src_lib.dir/abs_factory.cpp.o -c /shared/OnlineGetJob/DesignPattern/src/abs_factory.cpp

src/CMakeFiles/src_lib.dir/abs_factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src_lib.dir/abs_factory.cpp.i"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /shared/OnlineGetJob/DesignPattern/src/abs_factory.cpp > CMakeFiles/src_lib.dir/abs_factory.cpp.i

src/CMakeFiles/src_lib.dir/abs_factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src_lib.dir/abs_factory.cpp.s"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /shared/OnlineGetJob/DesignPattern/src/abs_factory.cpp -o CMakeFiles/src_lib.dir/abs_factory.cpp.s

src/CMakeFiles/src_lib.dir/builder.cpp.o: src/CMakeFiles/src_lib.dir/flags.make
src/CMakeFiles/src_lib.dir/builder.cpp.o: ../src/builder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/shared/OnlineGetJob/DesignPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/src_lib.dir/builder.cpp.o"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src_lib.dir/builder.cpp.o -c /shared/OnlineGetJob/DesignPattern/src/builder.cpp

src/CMakeFiles/src_lib.dir/builder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src_lib.dir/builder.cpp.i"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /shared/OnlineGetJob/DesignPattern/src/builder.cpp > CMakeFiles/src_lib.dir/builder.cpp.i

src/CMakeFiles/src_lib.dir/builder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src_lib.dir/builder.cpp.s"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /shared/OnlineGetJob/DesignPattern/src/builder.cpp -o CMakeFiles/src_lib.dir/builder.cpp.s

src/CMakeFiles/src_lib.dir/combine.cpp.o: src/CMakeFiles/src_lib.dir/flags.make
src/CMakeFiles/src_lib.dir/combine.cpp.o: ../src/combine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/shared/OnlineGetJob/DesignPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/src_lib.dir/combine.cpp.o"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src_lib.dir/combine.cpp.o -c /shared/OnlineGetJob/DesignPattern/src/combine.cpp

src/CMakeFiles/src_lib.dir/combine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src_lib.dir/combine.cpp.i"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /shared/OnlineGetJob/DesignPattern/src/combine.cpp > CMakeFiles/src_lib.dir/combine.cpp.i

src/CMakeFiles/src_lib.dir/combine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src_lib.dir/combine.cpp.s"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /shared/OnlineGetJob/DesignPattern/src/combine.cpp -o CMakeFiles/src_lib.dir/combine.cpp.s

src/CMakeFiles/src_lib.dir/command.cpp.o: src/CMakeFiles/src_lib.dir/flags.make
src/CMakeFiles/src_lib.dir/command.cpp.o: ../src/command.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/shared/OnlineGetJob/DesignPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/src_lib.dir/command.cpp.o"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src_lib.dir/command.cpp.o -c /shared/OnlineGetJob/DesignPattern/src/command.cpp

src/CMakeFiles/src_lib.dir/command.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src_lib.dir/command.cpp.i"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /shared/OnlineGetJob/DesignPattern/src/command.cpp > CMakeFiles/src_lib.dir/command.cpp.i

src/CMakeFiles/src_lib.dir/command.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src_lib.dir/command.cpp.s"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /shared/OnlineGetJob/DesignPattern/src/command.cpp -o CMakeFiles/src_lib.dir/command.cpp.s

src/CMakeFiles/src_lib.dir/facada.cpp.o: src/CMakeFiles/src_lib.dir/flags.make
src/CMakeFiles/src_lib.dir/facada.cpp.o: ../src/facada.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/shared/OnlineGetJob/DesignPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/src_lib.dir/facada.cpp.o"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src_lib.dir/facada.cpp.o -c /shared/OnlineGetJob/DesignPattern/src/facada.cpp

src/CMakeFiles/src_lib.dir/facada.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src_lib.dir/facada.cpp.i"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /shared/OnlineGetJob/DesignPattern/src/facada.cpp > CMakeFiles/src_lib.dir/facada.cpp.i

src/CMakeFiles/src_lib.dir/facada.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src_lib.dir/facada.cpp.s"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /shared/OnlineGetJob/DesignPattern/src/facada.cpp -o CMakeFiles/src_lib.dir/facada.cpp.s

src/CMakeFiles/src_lib.dir/single.cpp.o: src/CMakeFiles/src_lib.dir/flags.make
src/CMakeFiles/src_lib.dir/single.cpp.o: ../src/single.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/shared/OnlineGetJob/DesignPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/src_lib.dir/single.cpp.o"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src_lib.dir/single.cpp.o -c /shared/OnlineGetJob/DesignPattern/src/single.cpp

src/CMakeFiles/src_lib.dir/single.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src_lib.dir/single.cpp.i"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /shared/OnlineGetJob/DesignPattern/src/single.cpp > CMakeFiles/src_lib.dir/single.cpp.i

src/CMakeFiles/src_lib.dir/single.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src_lib.dir/single.cpp.s"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /shared/OnlineGetJob/DesignPattern/src/single.cpp -o CMakeFiles/src_lib.dir/single.cpp.s

src/CMakeFiles/src_lib.dir/template.cpp.o: src/CMakeFiles/src_lib.dir/flags.make
src/CMakeFiles/src_lib.dir/template.cpp.o: ../src/template.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/shared/OnlineGetJob/DesignPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/src_lib.dir/template.cpp.o"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src_lib.dir/template.cpp.o -c /shared/OnlineGetJob/DesignPattern/src/template.cpp

src/CMakeFiles/src_lib.dir/template.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src_lib.dir/template.cpp.i"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /shared/OnlineGetJob/DesignPattern/src/template.cpp > CMakeFiles/src_lib.dir/template.cpp.i

src/CMakeFiles/src_lib.dir/template.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src_lib.dir/template.cpp.s"
	cd /shared/OnlineGetJob/DesignPattern/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /shared/OnlineGetJob/DesignPattern/src/template.cpp -o CMakeFiles/src_lib.dir/template.cpp.s

# Object files for target src_lib
src_lib_OBJECTS = \
"CMakeFiles/src_lib.dir/abs_factory.cpp.o" \
"CMakeFiles/src_lib.dir/builder.cpp.o" \
"CMakeFiles/src_lib.dir/combine.cpp.o" \
"CMakeFiles/src_lib.dir/command.cpp.o" \
"CMakeFiles/src_lib.dir/facada.cpp.o" \
"CMakeFiles/src_lib.dir/single.cpp.o" \
"CMakeFiles/src_lib.dir/template.cpp.o"

# External object files for target src_lib
src_lib_EXTERNAL_OBJECTS =

src/libsrc_lib.a: src/CMakeFiles/src_lib.dir/abs_factory.cpp.o
src/libsrc_lib.a: src/CMakeFiles/src_lib.dir/builder.cpp.o
src/libsrc_lib.a: src/CMakeFiles/src_lib.dir/combine.cpp.o
src/libsrc_lib.a: src/CMakeFiles/src_lib.dir/command.cpp.o
src/libsrc_lib.a: src/CMakeFiles/src_lib.dir/facada.cpp.o
src/libsrc_lib.a: src/CMakeFiles/src_lib.dir/single.cpp.o
src/libsrc_lib.a: src/CMakeFiles/src_lib.dir/template.cpp.o
src/libsrc_lib.a: src/CMakeFiles/src_lib.dir/build.make
src/libsrc_lib.a: src/CMakeFiles/src_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/shared/OnlineGetJob/DesignPattern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libsrc_lib.a"
	cd /shared/OnlineGetJob/DesignPattern/build/src && $(CMAKE_COMMAND) -P CMakeFiles/src_lib.dir/cmake_clean_target.cmake
	cd /shared/OnlineGetJob/DesignPattern/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/src_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/src_lib.dir/build: src/libsrc_lib.a

.PHONY : src/CMakeFiles/src_lib.dir/build

src/CMakeFiles/src_lib.dir/clean:
	cd /shared/OnlineGetJob/DesignPattern/build/src && $(CMAKE_COMMAND) -P CMakeFiles/src_lib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/src_lib.dir/clean

src/CMakeFiles/src_lib.dir/depend:
	cd /shared/OnlineGetJob/DesignPattern/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /shared/OnlineGetJob/DesignPattern /shared/OnlineGetJob/DesignPattern/src /shared/OnlineGetJob/DesignPattern/build /shared/OnlineGetJob/DesignPattern/build/src /shared/OnlineGetJob/DesignPattern/build/src/CMakeFiles/src_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/src_lib.dir/depend

