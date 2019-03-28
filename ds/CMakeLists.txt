cmake_minimum_required(VERSION 3.10)
project(ds)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(./src DIR_SRC)

add_executable(ds ${DIR_SRC})