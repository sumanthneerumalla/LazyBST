cmake_minimum_required(VERSION 3.6)
project(proj3)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES test1.cpp LazyBST.cpp LazyBST.h)
add_executable(proj3 ${SOURCE_FILES})