# CMakeList.txt : CMake project for string-benchmark, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (string-benchmark "string-benchmark.cpp" "string-benchmark.h")

target_link_libraries("string-benchmark" benchmark::benchmark absl::strings)
