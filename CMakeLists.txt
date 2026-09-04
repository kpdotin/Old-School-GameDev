cmake_minimum_required(VERSION 4.3)
project(Old_School_GameDev)

set(CMAKE_CXX_STANDARD 26)

#find the package
#set(RAYLIB_VERSION 6.0)
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            GIT_REPOSITORY https://github.com/raysan5/raylib.git
            #GIT_TAG ${RAYLIB_VERSION}
    )
    FetchContent_MakeAvailable(raylib)
endif ()

#add executable (must happen before running target_link_libraries)
add_executable(Old_School_GameDev main.cpp)

# link the library now
target_link_libraries(Old_School_GameDev PRIVATE raylib)
