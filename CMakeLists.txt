cmake_minimum_required(VERSION 3.10)

# Project name
project(math_lib)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# # Find the NLopt package
# find_package(NLopt REQUIRED)
include_directories(include)

set(SOURCES
    src/main.cpp
    src/custom_int.cpp
    src/custom_float.cpp
)

set(HEADERS
    include/arbitrary_vector.hpp
    include/matrix.hpp
    include/vector3d.hpp
    include/custom_int.hpp
    include/custom_float.hpp
    include/general_math.hpp

)
# # Include directories
# include_directories(${NLOPT_INCLUDE_DIRS})

# Add executable
add_executable(math_lib ${SOURCES} ${HEADERS})

# # Link libraries
# target_link_libraries(math_lib ${NLOPT_LIBRARIES})
