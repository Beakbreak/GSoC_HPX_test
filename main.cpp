#include <hpx/algorithm.hpp>
#include <hpx/execution.hpp>
#include <hpx/init.hpp>
#include <hpx/program_options.hpp>
#include <cstddef>
#include <iostream>
#include <vector>

void print_matrix(std::vector<int> const& M, std::size_t rows, std::size_t cols,
    char const* message)
{
    std::cout << "\nMatrix " << message << " is:" << std::endl;
    for (std::size_t i = 0; i < rows; i++)
    {
        for (std::size_t j = 0; j < cols; j++)
            std::cout << M[i * cols + j] << " ";
        std::cout << "\n";
    }
}

int hpx_main(hpx::program_options::variables_map& vm)
{
    using element_type = int;

    // Define matrix sizes
    std::size_t const rowsA = vm["n"].as<std::size_t>();
    std::size_t const colsA = vm["m"].as<std::size_t>();
    std::size_t const rowsB = colsA;
    std::size_t const colsB = vm["k"].as<std::size_t>();
    std::size_t const rowsR = rowsA;
    std::size_t const colsR = colsB;

    // Initialize matrices A and B
    std::vector<int> A(rowsA * colsA);
    std::vector<int> B(rowsB * colsB);
    std::vector<int> R(rowsR * colsR);

    // Prompt user to enter values for matrix A
    std::cout << "Enter elements of matrix A (" << rowsA << "x" << colsA << "):" << std::endl;
    for (std::size_t i = 0; i < rowsA; ++i) {
        for (std::size_t j = 0; j < colsA; ++j) {
            std::cout << "A[" << i << "][" << j << "]: ";
            std::cin >> A[i * colsA + j];
        }
    }

    // Prompt user to enter values for matrix B
    std::cout << "Enter elements of matrix B (" << rowsB << "x" << colsB << "):" << std::endl;
    for (std::size_t i = 0; i < rowsB; ++i) {
        for (std::size_t j = 0; j < colsB; ++j) {
            std::cout << "B[" << i << "][" << j << "]: ";
            std::cin >> B[i * colsB + j];
        }
    }

    // Perform matrix multiplication
    for (std::size_t i = 0; i < rowsA; ++i) {
        for (std::size_t j = 0; j < colsB; ++j) {
            R[i * colsR + j] = 0;
            for (std::size_t k = 0; k < rowsB; ++k) {
                R[i * colsR + j] += A[i * colsA + k] * B[k * colsB + j];
            }
        }
    }

    // Print all 3 matrices
    print_matrix(A, rowsA, colsA, "A");
    print_matrix(B, rowsB, colsB, "B");
    print_matrix(R, rowsR, colsR, "R");

    return hpx::finalize();
}

int main(int argc, char* argv[])
{
    using namespace hpx::program_options;
    options_description cmdline("usage: " HPX_APPLICATION_STRING " [options]");
    // clang-format off
    cmdline.add_options()
        ("n",
        hpx::program_options::value<std::size_t>()->default_value(2),
        "Number of rows of first matrix")
        ("m",
        hpx::program_options::value<std::size_t>()->default_value(3),
        "Number of columns of first matrix (equal to the number of rows of "
        "second matrix)")
        ("k",
        hpx::program_options::value<std::size_t>()->default_value(2),
        "Number of columns of second matrix")
        ("seed,s",
        hpx::program_options::value<unsigned int>(),
        "The random number generator seed to use for this run")
        ("l",
        hpx::program_options::value<int>()->default_value(0),
        "Lower limit of range of values")
        ("u",
        hpx::program_options::value<int>()->default_value(10),
        "Upper limit of range of values");
    // clang-format on
    hpx::init_params init_args;
    init_args.desc_cmdline = cmdline;

    return hpx::init(argc, argv, init_args);
}
