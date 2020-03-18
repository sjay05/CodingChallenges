cmake_minimum_required(VERSION 3.15)
project(DsAlgoC__)

set(CMAKE_CXX_STANDARD 20)

add_executable(0-1_knapsack Algorithms/DP/0-1_knapsack.cpp)
add_executable(lis Algorithms/DP/lis.cpp)
add_executable(dup_knapsack Algorithms/DP/dup_knapsack.cpp)
add_executable(test Algorithms/DP/test.cpp)
add_executable(S4 Algorithms/DP/S4.cpp)