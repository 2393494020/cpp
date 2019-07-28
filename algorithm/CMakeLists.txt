cmake_minimum_required(VERSION 3.5)
project(algorithm)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(./src DIR_SRC)

add_executable(algorithm ${DIR_SRC})
