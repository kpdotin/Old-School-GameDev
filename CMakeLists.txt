cmake_minimum_required(VERSION 4.3)
project(Old_School_GameDev)

set(CMAKE_CXX_STANDARD 26)

#find the package
find_package(raylib CONFIG REQUIRED)

#add executable (must happen before running target_link_libraries)
add_executable(Old_School_GameDev main.cpp)

# link the library now
target_link_libraries(Old_School_GameDev PRIVATE raylib)
