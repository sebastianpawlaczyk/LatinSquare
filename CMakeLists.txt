cmake_minimum_required(VERSION 3.10)
project(LatinSquare)

set(CMAKE_CXX_STANDARD 11)

add_executable(LatinSquare main.cpp src/fwd.hpp src/sdk/LifeStarter.cpp src/sdk/LifeStarter.hpp  src/latin/LatingSquareAlgorithm.cpp src/latin/LatingSquareAlgorithm.hpp src/latin/AlgorithmHelper.cpp src/latin/AlgorithmHelper.hpp)