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
CMAKE_SOURCE_DIR = /home/hfwang/dev/projects/mprpc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hfwang/dev/projects/mprpc/build

# Include any dependencies generated for this target.
include src/CMakeFiles/mprpc.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/mprpc.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/mprpc.dir/flags.make

src/CMakeFiles/mprpc.dir/MpRpcApplication.cc.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/MpRpcApplication.cc.o: ../src/MpRpcApplication.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hfwang/dev/projects/mprpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/mprpc.dir/MpRpcApplication.cc.o"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mprpc.dir/MpRpcApplication.cc.o -c /home/hfwang/dev/projects/mprpc/src/MpRpcApplication.cc

src/CMakeFiles/mprpc.dir/MpRpcApplication.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/MpRpcApplication.cc.i"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hfwang/dev/projects/mprpc/src/MpRpcApplication.cc > CMakeFiles/mprpc.dir/MpRpcApplication.cc.i

src/CMakeFiles/mprpc.dir/MpRpcApplication.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/MpRpcApplication.cc.s"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hfwang/dev/projects/mprpc/src/MpRpcApplication.cc -o CMakeFiles/mprpc.dir/MpRpcApplication.cc.s

src/CMakeFiles/mprpc.dir/MpRpcChannel.cc.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/MpRpcChannel.cc.o: ../src/MpRpcChannel.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hfwang/dev/projects/mprpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/mprpc.dir/MpRpcChannel.cc.o"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mprpc.dir/MpRpcChannel.cc.o -c /home/hfwang/dev/projects/mprpc/src/MpRpcChannel.cc

src/CMakeFiles/mprpc.dir/MpRpcChannel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/MpRpcChannel.cc.i"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hfwang/dev/projects/mprpc/src/MpRpcChannel.cc > CMakeFiles/mprpc.dir/MpRpcChannel.cc.i

src/CMakeFiles/mprpc.dir/MpRpcChannel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/MpRpcChannel.cc.s"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hfwang/dev/projects/mprpc/src/MpRpcChannel.cc -o CMakeFiles/mprpc.dir/MpRpcChannel.cc.s

src/CMakeFiles/mprpc.dir/MpRpcConfig.cc.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/MpRpcConfig.cc.o: ../src/MpRpcConfig.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hfwang/dev/projects/mprpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/mprpc.dir/MpRpcConfig.cc.o"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mprpc.dir/MpRpcConfig.cc.o -c /home/hfwang/dev/projects/mprpc/src/MpRpcConfig.cc

src/CMakeFiles/mprpc.dir/MpRpcConfig.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/MpRpcConfig.cc.i"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hfwang/dev/projects/mprpc/src/MpRpcConfig.cc > CMakeFiles/mprpc.dir/MpRpcConfig.cc.i

src/CMakeFiles/mprpc.dir/MpRpcConfig.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/MpRpcConfig.cc.s"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hfwang/dev/projects/mprpc/src/MpRpcConfig.cc -o CMakeFiles/mprpc.dir/MpRpcConfig.cc.s

src/CMakeFiles/mprpc.dir/MpRpcController.cc.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/MpRpcController.cc.o: ../src/MpRpcController.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hfwang/dev/projects/mprpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/mprpc.dir/MpRpcController.cc.o"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mprpc.dir/MpRpcController.cc.o -c /home/hfwang/dev/projects/mprpc/src/MpRpcController.cc

src/CMakeFiles/mprpc.dir/MpRpcController.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/MpRpcController.cc.i"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hfwang/dev/projects/mprpc/src/MpRpcController.cc > CMakeFiles/mprpc.dir/MpRpcController.cc.i

src/CMakeFiles/mprpc.dir/MpRpcController.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/MpRpcController.cc.s"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hfwang/dev/projects/mprpc/src/MpRpcController.cc -o CMakeFiles/mprpc.dir/MpRpcController.cc.s

src/CMakeFiles/mprpc.dir/MpRpcLogger.cc.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/MpRpcLogger.cc.o: ../src/MpRpcLogger.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hfwang/dev/projects/mprpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/mprpc.dir/MpRpcLogger.cc.o"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mprpc.dir/MpRpcLogger.cc.o -c /home/hfwang/dev/projects/mprpc/src/MpRpcLogger.cc

src/CMakeFiles/mprpc.dir/MpRpcLogger.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/MpRpcLogger.cc.i"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hfwang/dev/projects/mprpc/src/MpRpcLogger.cc > CMakeFiles/mprpc.dir/MpRpcLogger.cc.i

src/CMakeFiles/mprpc.dir/MpRpcLogger.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/MpRpcLogger.cc.s"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hfwang/dev/projects/mprpc/src/MpRpcLogger.cc -o CMakeFiles/mprpc.dir/MpRpcLogger.cc.s

src/CMakeFiles/mprpc.dir/RpcHeader.pb.cc.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/RpcHeader.pb.cc.o: ../src/RpcHeader.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hfwang/dev/projects/mprpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/mprpc.dir/RpcHeader.pb.cc.o"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mprpc.dir/RpcHeader.pb.cc.o -c /home/hfwang/dev/projects/mprpc/src/RpcHeader.pb.cc

src/CMakeFiles/mprpc.dir/RpcHeader.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/RpcHeader.pb.cc.i"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hfwang/dev/projects/mprpc/src/RpcHeader.pb.cc > CMakeFiles/mprpc.dir/RpcHeader.pb.cc.i

src/CMakeFiles/mprpc.dir/RpcHeader.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/RpcHeader.pb.cc.s"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hfwang/dev/projects/mprpc/src/RpcHeader.pb.cc -o CMakeFiles/mprpc.dir/RpcHeader.pb.cc.s

src/CMakeFiles/mprpc.dir/RpcProvider.cc.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/RpcProvider.cc.o: ../src/RpcProvider.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hfwang/dev/projects/mprpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/mprpc.dir/RpcProvider.cc.o"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mprpc.dir/RpcProvider.cc.o -c /home/hfwang/dev/projects/mprpc/src/RpcProvider.cc

src/CMakeFiles/mprpc.dir/RpcProvider.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/RpcProvider.cc.i"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hfwang/dev/projects/mprpc/src/RpcProvider.cc > CMakeFiles/mprpc.dir/RpcProvider.cc.i

src/CMakeFiles/mprpc.dir/RpcProvider.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/RpcProvider.cc.s"
	cd /home/hfwang/dev/projects/mprpc/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hfwang/dev/projects/mprpc/src/RpcProvider.cc -o CMakeFiles/mprpc.dir/RpcProvider.cc.s

# Object files for target mprpc
mprpc_OBJECTS = \
"CMakeFiles/mprpc.dir/MpRpcApplication.cc.o" \
"CMakeFiles/mprpc.dir/MpRpcChannel.cc.o" \
"CMakeFiles/mprpc.dir/MpRpcConfig.cc.o" \
"CMakeFiles/mprpc.dir/MpRpcController.cc.o" \
"CMakeFiles/mprpc.dir/MpRpcLogger.cc.o" \
"CMakeFiles/mprpc.dir/RpcHeader.pb.cc.o" \
"CMakeFiles/mprpc.dir/RpcProvider.cc.o"

# External object files for target mprpc
mprpc_EXTERNAL_OBJECTS =

../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/MpRpcApplication.cc.o
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/MpRpcChannel.cc.o
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/MpRpcConfig.cc.o
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/MpRpcController.cc.o
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/MpRpcLogger.cc.o
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/RpcHeader.pb.cc.o
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/RpcProvider.cc.o
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/build.make
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hfwang/dev/projects/mprpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library ../../lib/libmprpc.a"
	cd /home/hfwang/dev/projects/mprpc/build/src && $(CMAKE_COMMAND) -P CMakeFiles/mprpc.dir/cmake_clean_target.cmake
	cd /home/hfwang/dev/projects/mprpc/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mprpc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/mprpc.dir/build: ../lib/libmprpc.a

.PHONY : src/CMakeFiles/mprpc.dir/build

src/CMakeFiles/mprpc.dir/clean:
	cd /home/hfwang/dev/projects/mprpc/build/src && $(CMAKE_COMMAND) -P CMakeFiles/mprpc.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/mprpc.dir/clean

src/CMakeFiles/mprpc.dir/depend:
	cd /home/hfwang/dev/projects/mprpc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hfwang/dev/projects/mprpc /home/hfwang/dev/projects/mprpc/src /home/hfwang/dev/projects/mprpc/build /home/hfwang/dev/projects/mprpc/build/src /home/hfwang/dev/projects/mprpc/build/src/CMakeFiles/mprpc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/mprpc.dir/depend

