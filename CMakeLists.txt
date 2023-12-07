cmake_minimum_required(VERSION 3.26)
project(string_composition)

set(CMAKE_CXX_STANDARD 20)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmodules-ts")

add_executable(string_composition string_composition.cpp)
add_executable(string_spelled_by_genome_path string_spelled_by_genome_path.cpp)
add_executable(overlap_graph_problem overlap_graph_problem.cpp)
add_executable(stringToDeBruijn stringToDeBruijn.cpp)
add_executable(kmers_to_DeBruijn kmers_to_DeBruijn.cpp)
