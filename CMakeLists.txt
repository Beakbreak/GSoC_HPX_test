cmake_minimum_required(VERSION 3.10)
project(MatrixMultiplication CXX)
find_package(HPX REQUIRED)
add_executable(matrix_multiplication main.cpp)
target_link_libraries(matrix_multiplication PUBLIC HPX::hpx)

