cmake_minimum_required(VERSION 4.1)
project(Week_3)

set(CMAKE_CXX_STANDARD 20)
find_package(raylib CONFIG REQUIRED)
add_executable(Week_3 main.cpp)
target_link_libraries(Week_3 PRIVATE raylib)
