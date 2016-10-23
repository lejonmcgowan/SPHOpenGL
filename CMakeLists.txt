cmake_minimum_required(VERSION 2.8)

project(Final)

INCLUDE_DIRECTORIES ( Eigen )

SET(GCC_COVERAGE_COMPILE_FLAGS "-g -ansi -pedantic -Wno-deprecated -std=c++11 -O3")
SET(GCC_COVERAGE_LINK_FLAGS    "-DGL_GLEXT_PROTOTYPES -lglut -lGL -lGLU")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
add_definitions(${GCC_COVERAGE_LINK_FLAGS})

# FIND GLUT
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})

# FIND OPENGL
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

ADD_EXECUTABLE(Final Camera.cpp GridManager.cpp Kernel.cpp MatrixStack.cpp Program.cpp Texture.cpp GLSL.cpp HUD.cpp main.cpp Particle.cpp SPHSolver.cpp)


target_link_libraries(Final ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
