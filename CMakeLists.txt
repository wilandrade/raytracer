cmake_minimum_required(VERSION 3.10)
project(RayTracer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
file(GLOB SOURCES 
    "src/*.cpp"
    "src/*.h"
)

# Create executable
add_executable(raytracer ${SOURCES})

# Include directories
target_include_directories(raytracer PRIVATE 
    ${CMAKE_SOURCE_DIR}/src
) 