# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("string-benchmark")

set(CMAKE_CXX_STANDARD 17)
set(gtest_force_shared_crt On)

include_directories(google-benchmark/include)
include_directories(abseil)

add_subdirectory(google-test)
add_subdirectory(google-benchmark)
add_subdirectory(abseil)

# Include sub-projects.
add_subdirectory ("string-benchmark")
