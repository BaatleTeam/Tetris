cmake_minimum_required(VERSION 3.3)

set(EXECUTABLE_OUTPUT_PATH "Build")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall")

project(Tetris)
   
# Adding source files
file(GLOB src Source/*.cpp)
   
# Adding dependencies
find_package(OpenGL 3.3 REQUIRED) # Or 3.2?
	include_directories(${OPENGL_INCLUDE_DIRS})
	link_libraries(${OPENGL_LIBRARIES})
find_package(GLEW REQUIRED)
	include_directories(${GLEW_INCLUDE_DIRS})
	link_libraries(${GLEW_LIBRARIES})
find_package(SFML REQUIRED window graphics)

# Compiling
add_executable(Tetris ${src})
target_link_libraries(Tetris sfml-window sfml-graphics)

