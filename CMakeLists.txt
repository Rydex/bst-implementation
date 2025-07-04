cmake_minimum_required(VERSION 3.16)
project(bstimpl)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
	tests.cpp
	src/bst.cpp
)

add_library(mylib
	src/bst.cpp
	src/bst.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE mylib)