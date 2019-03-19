cmake_minimum_required(VERSION 3.13)
project(CPP_Projects)

set(CMAKE_CXX_STANDARD 14)

include_directories(Matala2)

add_executable(CPP_Projects
        Matala2/Node.cpp
        Matala2/test.cpp
        Matala2/Tree.cpp
        Matala2/Tree.hpp)
