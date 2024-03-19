# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/beakbreak/Desktop/GSoC_HPX_test/build/_deps/hwloc-src"
  "/home/beakbreak/Desktop/GSoC_HPX_test/build/_deps/hwloc-build"
  "/home/beakbreak/Desktop/GSoC_HPX_test/build/_deps/hwloc-subbuild/hwloc-populate-prefix"
  "/home/beakbreak/Desktop/GSoC_HPX_test/build/_deps/hwloc-subbuild/hwloc-populate-prefix/tmp"
  "/home/beakbreak/Desktop/GSoC_HPX_test/build/_deps/hwloc-subbuild/hwloc-populate-prefix/src/hwloc-populate-stamp"
  "/home/beakbreak/Desktop/GSoC_HPX_test/build/_deps/hwloc-subbuild/hwloc-populate-prefix/src"
  "/home/beakbreak/Desktop/GSoC_HPX_test/build/_deps/hwloc-subbuild/hwloc-populate-prefix/src/hwloc-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/beakbreak/Desktop/GSoC_HPX_test/build/_deps/hwloc-subbuild/hwloc-populate-prefix/src/hwloc-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/beakbreak/Desktop/GSoC_HPX_test/build/_deps/hwloc-subbuild/hwloc-populate-prefix/src/hwloc-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
