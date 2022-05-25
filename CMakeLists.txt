cmake_minimum_required(VERSION 3.21)
project(Tetris)
set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

add_executable(Tetris main.cpp)
target_link_libraries(Tetris ${CURSES_LIBRARIES})
