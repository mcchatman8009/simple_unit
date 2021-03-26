cmake_minimum_required(VERSION 3.16)
project(simple_unit C)

set(CMAKE_C_STANDARD 99)

add_executable(simple_unit_test simple_unit.h test.c)
