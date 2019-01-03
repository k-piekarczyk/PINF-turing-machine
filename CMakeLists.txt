cmake_minimum_required(VERSION 3.13)
project(turing_machine C)

set(CMAKE_C_STANDARD 11)

add_executable(turing_machine main.c tm_list.c tm_list.h tm_load.c tm_load.h)