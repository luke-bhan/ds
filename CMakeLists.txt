cmake_minimum_required(VERSION 3.15)
project(ds)

set(CMAKE_CXX_STANDARD 20)

# include project header files
include_directories(./include)

# Set source files
set(SOURCE_FILES 
	src/Vector.cpp
	src/main.cpp
)

add_executable(ds ${SOURCE_FILES})
