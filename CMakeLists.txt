cmake_minimum_required(VERSION 3.16)
project(cjlsuper)

set(CMAKE_CXX_STANDARD 14)


add_executable(cjlsuper main.cpp)
add_executable(LinkedList LinkedList.cpp LinkedList.h)
add_executable(LinkedStack LinkedStack.cpp LinkedStack.h)
add_executable(ArrayStack ArrayStack.cpp ArrayStack.h)
add_executable(Day20200706 Day20200706.cpp)
add_executable(Day20200714 Day20200714.cpp)
add_executable(BST BST.cpp)
