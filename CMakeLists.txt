cmake_minimum_required(VERSION 3.15)

project(StringSearchBenchmark VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type selected, default to Release")
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

file(GLOB benchmark_SRC
    "*.h"
    "*.cpp"
)

add_executable(benchmark ${benchmark_SRC})
