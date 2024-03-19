# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.25.1)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(hwloc-populate NONE)



include(ExternalProject)
ExternalProject_Add(hwloc-populate
                     "UPDATE_DISCONNECTED" "False" "DOWNLOAD_EXTRACT_TIMESTAMP" "TRUE" "URL" "https://download.open-mpi.org/release/hwloc/v2.9/hwloc-2.9.3.tar.gz" "TLS_VERIFY" "true"
                    SOURCE_DIR          "/home/beakbreak/Desktop/GSoC_HPX_test/build/_deps/hwloc-src"
                    BINARY_DIR          "/home/beakbreak/Desktop/GSoC_HPX_test/build/_deps/hwloc-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
                    USES_TERMINAL_PATCH     YES
)


