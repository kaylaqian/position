cmake_minimum_required(VERSION 3.8)
project(xy)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp simulation.h simulation.cpp link.cpp link.h node.cpp node.h edge.h x.cpp x.h y.cpp y.h center.h center.cpp manybody.h manybody.cpp edge.cpp quad.h quad.cpp Quadtree.h Quadtree.cpp quadTree_fun.cpp quadTree_fun.h)
add_executable(xy ${SOURCE_FILES})