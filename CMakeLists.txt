cmake_minimum_required(VERSION 3.10)
project(MatrixMultiplicationExample)

find_package(HPX REQUIRED)

add_executable(matrix_multiplication matrix_multiplication.cpp)
target_link_libraries(matrix_multiplication PRIVATE HPX::hpx HPX::wrap_main)
