cmake_minimum_required(VERSION 3.3)

# set(EXECUTABLE_OUTPUT_PATH "Build")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

project(Tetris)
   
# Adding source files
file(GLOB_RECURSE srcMain Source/*.cpp)
# file(GLOB srcScreens Source/Screens/*.cpp)
# file(GLOB srcButtons Source/Buttons/*.cpp)
# file(GLOB srcSettings Source/Settings/*.cpp)
   
# Adding dependencies
find_package(OpenGL 3.3 REQUIRED) # Or 3.2?
	include_directories(${OPENGL_INCLUDE_DIRS})
	link_libraries(${OPENGL_LIBRARIES})
find_package(SFML 2.5 REQUIRED window graphics)

# Compiling
add_executable(Tetris ${srcMain} ${srcScreens} ${srcButtons} ${srcSettings})
target_link_libraries(Tetris sfml-window sfml-graphics)

