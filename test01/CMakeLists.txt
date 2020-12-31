# CMakeList.txt : CMake project for cpp_cmake2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (test01 "test01.cpp" "test01.h" "test02_thr.cpp" "util.cpp")

# TODO: Add tests and install targets if needed.
