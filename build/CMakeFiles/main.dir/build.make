# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /root/uwoc_sigGen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/uwoc_sigGen/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/uwoc_sigGen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/main.cpp.o -c /root/uwoc_sigGen/main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/uwoc_sigGen/main.cpp > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/uwoc_sigGen/main.cpp -o CMakeFiles/main.dir/main.cpp.s

CMakeFiles/main.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/main.cpp.o.requires

CMakeFiles/main.dir/main.cpp.o.provides: CMakeFiles/main.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/main.cpp.o.provides

CMakeFiles/main.dir/main.cpp.o.provides.build: CMakeFiles/main.dir/main.cpp.o


CMakeFiles/main.dir/generator.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/generator.cpp.o: ../generator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/uwoc_sigGen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/generator.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/generator.cpp.o -c /root/uwoc_sigGen/generator.cpp

CMakeFiles/main.dir/generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/generator.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/uwoc_sigGen/generator.cpp > CMakeFiles/main.dir/generator.cpp.i

CMakeFiles/main.dir/generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/generator.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/uwoc_sigGen/generator.cpp -o CMakeFiles/main.dir/generator.cpp.s

CMakeFiles/main.dir/generator.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/generator.cpp.o.requires

CMakeFiles/main.dir/generator.cpp.o.provides: CMakeFiles/main.dir/generator.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/generator.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/generator.cpp.o.provides

CMakeFiles/main.dir/generator.cpp.o.provides.build: CMakeFiles/main.dir/generator.cpp.o


CMakeFiles/main.dir/generator_thread.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/generator_thread.cpp.o: ../generator_thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/uwoc_sigGen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/generator_thread.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/generator_thread.cpp.o -c /root/uwoc_sigGen/generator_thread.cpp

CMakeFiles/main.dir/generator_thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/generator_thread.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/uwoc_sigGen/generator_thread.cpp > CMakeFiles/main.dir/generator_thread.cpp.i

CMakeFiles/main.dir/generator_thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/generator_thread.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/uwoc_sigGen/generator_thread.cpp -o CMakeFiles/main.dir/generator_thread.cpp.s

CMakeFiles/main.dir/generator_thread.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/generator_thread.cpp.o.requires

CMakeFiles/main.dir/generator_thread.cpp.o.provides: CMakeFiles/main.dir/generator_thread.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/generator_thread.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/generator_thread.cpp.o.provides

CMakeFiles/main.dir/generator_thread.cpp.o.provides.build: CMakeFiles/main.dir/generator_thread.cpp.o


CMakeFiles/main.dir/buffer.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/buffer.cpp.o: ../buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/uwoc_sigGen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/buffer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/buffer.cpp.o -c /root/uwoc_sigGen/buffer.cpp

CMakeFiles/main.dir/buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/buffer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/uwoc_sigGen/buffer.cpp > CMakeFiles/main.dir/buffer.cpp.i

CMakeFiles/main.dir/buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/buffer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/uwoc_sigGen/buffer.cpp -o CMakeFiles/main.dir/buffer.cpp.s

CMakeFiles/main.dir/buffer.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/buffer.cpp.o.requires

CMakeFiles/main.dir/buffer.cpp.o.provides: CMakeFiles/main.dir/buffer.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/buffer.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/buffer.cpp.o.provides

CMakeFiles/main.dir/buffer.cpp.o.provides.build: CMakeFiles/main.dir/buffer.cpp.o


CMakeFiles/main.dir/reader.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/reader.cpp.o: ../reader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/uwoc_sigGen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/reader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/reader.cpp.o -c /root/uwoc_sigGen/reader.cpp

CMakeFiles/main.dir/reader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/reader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/uwoc_sigGen/reader.cpp > CMakeFiles/main.dir/reader.cpp.i

CMakeFiles/main.dir/reader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/reader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/uwoc_sigGen/reader.cpp -o CMakeFiles/main.dir/reader.cpp.s

CMakeFiles/main.dir/reader.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/reader.cpp.o.requires

CMakeFiles/main.dir/reader.cpp.o.provides: CMakeFiles/main.dir/reader.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/reader.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/reader.cpp.o.provides

CMakeFiles/main.dir/reader.cpp.o.provides.build: CMakeFiles/main.dir/reader.cpp.o


CMakeFiles/main.dir/reader_thread.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/reader_thread.cpp.o: ../reader_thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/uwoc_sigGen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.dir/reader_thread.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/reader_thread.cpp.o -c /root/uwoc_sigGen/reader_thread.cpp

CMakeFiles/main.dir/reader_thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/reader_thread.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/uwoc_sigGen/reader_thread.cpp > CMakeFiles/main.dir/reader_thread.cpp.i

CMakeFiles/main.dir/reader_thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/reader_thread.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/uwoc_sigGen/reader_thread.cpp -o CMakeFiles/main.dir/reader_thread.cpp.s

CMakeFiles/main.dir/reader_thread.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/reader_thread.cpp.o.requires

CMakeFiles/main.dir/reader_thread.cpp.o.provides: CMakeFiles/main.dir/reader_thread.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/reader_thread.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/reader_thread.cpp.o.provides

CMakeFiles/main.dir/reader_thread.cpp.o.provides.build: CMakeFiles/main.dir/reader_thread.cpp.o


CMakeFiles/main.dir/kiss_fft.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/kiss_fft.c.o: ../kiss_fft.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/uwoc_sigGen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/main.dir/kiss_fft.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/main.dir/kiss_fft.c.o   -c /root/uwoc_sigGen/kiss_fft.c

CMakeFiles/main.dir/kiss_fft.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/kiss_fft.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/uwoc_sigGen/kiss_fft.c > CMakeFiles/main.dir/kiss_fft.c.i

CMakeFiles/main.dir/kiss_fft.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/kiss_fft.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/uwoc_sigGen/kiss_fft.c -o CMakeFiles/main.dir/kiss_fft.c.s

CMakeFiles/main.dir/kiss_fft.c.o.requires:

.PHONY : CMakeFiles/main.dir/kiss_fft.c.o.requires

CMakeFiles/main.dir/kiss_fft.c.o.provides: CMakeFiles/main.dir/kiss_fft.c.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/kiss_fft.c.o.provides.build
.PHONY : CMakeFiles/main.dir/kiss_fft.c.o.provides

CMakeFiles/main.dir/kiss_fft.c.o.provides.build: CMakeFiles/main.dir/kiss_fft.c.o


# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/generator.cpp.o" \
"CMakeFiles/main.dir/generator_thread.cpp.o" \
"CMakeFiles/main.dir/buffer.cpp.o" \
"CMakeFiles/main.dir/reader.cpp.o" \
"CMakeFiles/main.dir/reader_thread.cpp.o" \
"CMakeFiles/main.dir/kiss_fft.c.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/main.cpp.o
main: CMakeFiles/main.dir/generator.cpp.o
main: CMakeFiles/main.dir/generator_thread.cpp.o
main: CMakeFiles/main.dir/buffer.cpp.o
main: CMakeFiles/main.dir/reader.cpp.o
main: CMakeFiles/main.dir/reader_thread.cpp.o
main: CMakeFiles/main.dir/kiss_fft.c.o
main: CMakeFiles/main.dir/build.make
main: /opt/redpitaya/lib/librp.so
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/uwoc_sigGen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/requires: CMakeFiles/main.dir/main.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/generator.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/generator_thread.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/buffer.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/reader.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/reader_thread.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/kiss_fft.c.o.requires

.PHONY : CMakeFiles/main.dir/requires

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /root/uwoc_sigGen/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/uwoc_sigGen /root/uwoc_sigGen /root/uwoc_sigGen/build /root/uwoc_sigGen/build /root/uwoc_sigGen/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

