cmake_minimum_required(VERSION 3.16)
project(cjlsuper)

set(CMAKE_CXX_STANDARD 14)


add_executable(cjlsuper main.cpp )
add_executable(LinkedList LinkedList.cpp LinkedList.h)
add_executable(LinkedStack LinkedStack.cpp LinkedStack.h )
add_executable(ArrayStack ArrayStack.cpp ArrayStack.h )