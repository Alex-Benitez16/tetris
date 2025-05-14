cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(game LANGUAGES CXX)

# Set the C++ standard (adjust to your needs, e.g., 17 or 20)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ========== SOURCE FILE CONFIGURATION ==========
# 2. Collect all C++ files from src/ directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 3. Create executable from collected sources
add_executable(${PROJECT_NAME} ${SOURCES})

# 4. Add include directory for headers
target_include_directories(${PROJECT_NAME} PRIVATE include)
# ===============================================

# Dependencies (existing raylib configuration)
set(RAYLIB_VERSION 5.5)
find_package(raylib ${RAYLIB_VERSION} QUIET)
if (NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_MakeAvailable(raylib)
endif()

# Linking (comes AFTER executable creation)
target_link_libraries(${PROJECT_NAME} raylib)

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
