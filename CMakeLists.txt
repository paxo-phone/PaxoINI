cmake_minimum_required( VERSION 3.18 )
project( PaxoINI )

set(CMAKE_CXX_STANDARD 17)

file( GLOB_RECURSE src src/*.cpp )
set(CMAKE_CXX_FLAGS "-D DEBUG")
add_executable( main ${src} main.cpp )