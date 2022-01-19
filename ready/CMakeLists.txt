cmake_minimum_required(VERSION 3.8)

project(play)

aux_source_directory(string_class src)

add_executable(play ${src})
