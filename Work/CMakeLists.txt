project(work)
cmake_minimum_required(VERSION 2.6)
add_definitions("--std=c++14 -Wall -g")
aux_source_directory(. SRC)
add_executable(work ${SRC})