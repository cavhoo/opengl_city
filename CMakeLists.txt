cmake_minimum_required(VERSION 3.13)
project(opengl_city VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB_RECURSE SOURCES "src/*.cpp")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
add_executable(opengl_city ${SOURCES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(opengl_city ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
