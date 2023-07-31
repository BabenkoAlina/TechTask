# CMakeLists.txt

cmake_minimum_required(VERSION 3.23)
project(tech)

set(CMAKE_CXX_STANDARD 17)

add_library(filesearch STATIC filesearchlib.cpp)
add_executable(tech main.cpp main)
target_link_libraries(tech PRIVATE filesearch)
