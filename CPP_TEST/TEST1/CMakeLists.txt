cmake_minimum_required(VERSION 3.10)
project(TEST1)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(LibraryManagement
    src/main.cpp
    src/Line.cpp
    src/utils.cpp
    
)