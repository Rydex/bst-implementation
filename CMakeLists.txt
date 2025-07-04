cmake_minimum_required(VERSION 3.16)
project(bstimpl)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
	tests.cpp
	src/bst.cpp
)

add_library(mylib
	src/bst.cpp
	src/bst.h
)