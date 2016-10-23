# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/lejonmcgowan/Dropbox/projects/SPH

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lejonmcgowan/Dropbox/projects/SPH

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/lejonmcgowan/Dropbox/projects/SPH/CMakeFiles /home/lejonmcgowan/Dropbox/projects/SPH/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/lejonmcgowan/Dropbox/projects/SPH/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Final

# Build rule for target.
Final: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Final
.PHONY : Final

# fast build rule for target.
Final/fast:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/build
.PHONY : Final/fast

Camera.o: Camera.cpp.o

.PHONY : Camera.o

# target to build an object file
Camera.cpp.o:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/Camera.cpp.o
.PHONY : Camera.cpp.o

Camera.i: Camera.cpp.i

.PHONY : Camera.i

# target to preprocess a source file
Camera.cpp.i:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/Camera.cpp.i
.PHONY : Camera.cpp.i

Camera.s: Camera.cpp.s

.PHONY : Camera.s

# target to generate assembly for a file
Camera.cpp.s:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/Camera.cpp.s
.PHONY : Camera.cpp.s

GLSL.o: GLSL.cpp.o

.PHONY : GLSL.o

# target to build an object file
GLSL.cpp.o:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/GLSL.cpp.o
.PHONY : GLSL.cpp.o

GLSL.i: GLSL.cpp.i

.PHONY : GLSL.i

# target to preprocess a source file
GLSL.cpp.i:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/GLSL.cpp.i
.PHONY : GLSL.cpp.i

GLSL.s: GLSL.cpp.s

.PHONY : GLSL.s

# target to generate assembly for a file
GLSL.cpp.s:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/GLSL.cpp.s
.PHONY : GLSL.cpp.s

GridManager.o: GridManager.cpp.o

.PHONY : GridManager.o

# target to build an object file
GridManager.cpp.o:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/GridManager.cpp.o
.PHONY : GridManager.cpp.o

GridManager.i: GridManager.cpp.i

.PHONY : GridManager.i

# target to preprocess a source file
GridManager.cpp.i:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/GridManager.cpp.i
.PHONY : GridManager.cpp.i

GridManager.s: GridManager.cpp.s

.PHONY : GridManager.s

# target to generate assembly for a file
GridManager.cpp.s:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/GridManager.cpp.s
.PHONY : GridManager.cpp.s

HUD.o: HUD.cpp.o

.PHONY : HUD.o

# target to build an object file
HUD.cpp.o:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/HUD.cpp.o
.PHONY : HUD.cpp.o

HUD.i: HUD.cpp.i

.PHONY : HUD.i

# target to preprocess a source file
HUD.cpp.i:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/HUD.cpp.i
.PHONY : HUD.cpp.i

HUD.s: HUD.cpp.s

.PHONY : HUD.s

# target to generate assembly for a file
HUD.cpp.s:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/HUD.cpp.s
.PHONY : HUD.cpp.s

Kernel.o: Kernel.cpp.o

.PHONY : Kernel.o

# target to build an object file
Kernel.cpp.o:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/Kernel.cpp.o
.PHONY : Kernel.cpp.o

Kernel.i: Kernel.cpp.i

.PHONY : Kernel.i

# target to preprocess a source file
Kernel.cpp.i:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/Kernel.cpp.i
.PHONY : Kernel.cpp.i

Kernel.s: Kernel.cpp.s

.PHONY : Kernel.s

# target to generate assembly for a file
Kernel.cpp.s:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/Kernel.cpp.s
.PHONY : Kernel.cpp.s

MatrixStack.o: MatrixStack.cpp.o

.PHONY : MatrixStack.o

# target to build an object file
MatrixStack.cpp.o:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/MatrixStack.cpp.o
.PHONY : MatrixStack.cpp.o

MatrixStack.i: MatrixStack.cpp.i

.PHONY : MatrixStack.i

# target to preprocess a source file
MatrixStack.cpp.i:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/MatrixStack.cpp.i
.PHONY : MatrixStack.cpp.i

MatrixStack.s: MatrixStack.cpp.s

.PHONY : MatrixStack.s

# target to generate assembly for a file
MatrixStack.cpp.s:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/MatrixStack.cpp.s
.PHONY : MatrixStack.cpp.s

Particle.o: Particle.cpp.o

.PHONY : Particle.o

# target to build an object file
Particle.cpp.o:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/Particle.cpp.o
.PHONY : Particle.cpp.o

Particle.i: Particle.cpp.i

.PHONY : Particle.i

# target to preprocess a source file
Particle.cpp.i:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/Particle.cpp.i
.PHONY : Particle.cpp.i

Particle.s: Particle.cpp.s

.PHONY : Particle.s

# target to generate assembly for a file
Particle.cpp.s:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/Particle.cpp.s
.PHONY : Particle.cpp.s

Program.o: Program.cpp.o

.PHONY : Program.o

# target to build an object file
Program.cpp.o:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/Program.cpp.o
.PHONY : Program.cpp.o

Program.i: Program.cpp.i

.PHONY : Program.i

# target to preprocess a source file
Program.cpp.i:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/Program.cpp.i
.PHONY : Program.cpp.i

Program.s: Program.cpp.s

.PHONY : Program.s

# target to generate assembly for a file
Program.cpp.s:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/Program.cpp.s
.PHONY : Program.cpp.s

SPHSolver.o: SPHSolver.cpp.o

.PHONY : SPHSolver.o

# target to build an object file
SPHSolver.cpp.o:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/SPHSolver.cpp.o
.PHONY : SPHSolver.cpp.o

SPHSolver.i: SPHSolver.cpp.i

.PHONY : SPHSolver.i

# target to preprocess a source file
SPHSolver.cpp.i:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/SPHSolver.cpp.i
.PHONY : SPHSolver.cpp.i

SPHSolver.s: SPHSolver.cpp.s

.PHONY : SPHSolver.s

# target to generate assembly for a file
SPHSolver.cpp.s:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/SPHSolver.cpp.s
.PHONY : SPHSolver.cpp.s

Texture.o: Texture.cpp.o

.PHONY : Texture.o

# target to build an object file
Texture.cpp.o:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/Texture.cpp.o
.PHONY : Texture.cpp.o

Texture.i: Texture.cpp.i

.PHONY : Texture.i

# target to preprocess a source file
Texture.cpp.i:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/Texture.cpp.i
.PHONY : Texture.cpp.i

Texture.s: Texture.cpp.s

.PHONY : Texture.s

# target to generate assembly for a file
Texture.cpp.s:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/Texture.cpp.s
.PHONY : Texture.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/Final.dir/build.make CMakeFiles/Final.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Final"
	@echo "... Camera.o"
	@echo "... Camera.i"
	@echo "... Camera.s"
	@echo "... GLSL.o"
	@echo "... GLSL.i"
	@echo "... GLSL.s"
	@echo "... GridManager.o"
	@echo "... GridManager.i"
	@echo "... GridManager.s"
	@echo "... HUD.o"
	@echo "... HUD.i"
	@echo "... HUD.s"
	@echo "... Kernel.o"
	@echo "... Kernel.i"
	@echo "... Kernel.s"
	@echo "... MatrixStack.o"
	@echo "... MatrixStack.i"
	@echo "... MatrixStack.s"
	@echo "... Particle.o"
	@echo "... Particle.i"
	@echo "... Particle.s"
	@echo "... Program.o"
	@echo "... Program.i"
	@echo "... Program.s"
	@echo "... SPHSolver.o"
	@echo "... SPHSolver.i"
	@echo "... SPHSolver.s"
	@echo "... Texture.o"
	@echo "... Texture.i"
	@echo "... Texture.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
