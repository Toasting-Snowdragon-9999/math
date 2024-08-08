cmake_minimum_required(VERSION 3.12)
project(math)

# Include header files from the "libs" directory
include_directories(libs)

# Add cpp files from the "src" directory
file(GLOB SOURCES src/*.cpp)

# Specify C++ standard (optional but recommended)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add a library target if you have library files (optional)
# add_library(my_library libs/my_library.cpp)

# Link the library to the executable (optional)
# target_link_libraries(math my_library)

# Create an executable target
add_executable(math ${SOURCES})
