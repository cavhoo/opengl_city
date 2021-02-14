cmake_minimum_required(VERSION 3.13)
project(opengl_city VERSION 1.0
	DESCRIPTION "City generated in OpenGL"
	LANGUAGES CXX
	)

set(CMAKE_CXX_COMPILER "clang")
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(opengl_city ${SOURCE_FILES})

find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(GLUT REQUIRED)

add_dependencies(opengl_city OpenGL::OpenGL)
include_directories(${GLUT_INCLUDE_DIRS})
target_link_libraries(opengl_city OpenGL::OpenGL ${GLUT_LIBRARY})

#include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
