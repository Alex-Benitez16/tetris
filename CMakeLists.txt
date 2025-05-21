cmake_minimum_required(VERSION 3.11)
project(game LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ========== Source Configuration ==========
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include)

# ========== Raylib Configuration ==========
set(RAYLIB_VERSION 5.5)

# Force static build of Raylib and disable shared libs
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build static lib" FORCE)

# Optional: Disable X11 if you want to try avoiding the dependency
# set(USE_X11 OFF CACHE BOOL "Disable X11" FORCE)  # Not always available

find_package(raylib ${RAYLIB_VERSION} QUIET)
if(NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_MakeAvailable(raylib)
endif()

target_link_libraries(${PROJECT_NAME} raylib)

# ========== Platform-Specific Settings ==========
if(APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit" "-framework Cocoa" "-framework OpenGL")
endif()
