# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("ready")

# aux_source_directory(oop src)

add_executable (ready "reference.cpp")
