cmake_minimum_required(VERSION 3.8)

project(ready)

aux_source_directory(auto_ptr src)

add_executable(ready ${src})
