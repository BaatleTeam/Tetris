cmake_minimum_required(VERSION 3.12)

    set(EXECUTABLE_OUTPUT_PATH "Build")

    project(Tetris)
    
    file(GLOB src Source/*.cpp)
    file(GLOB sfml_libs Source/SFML/*.dll)

    add_executable(Tetris ${src})
    target_link_libraries(Tetris ${sfml_libs})

