cmake_minimum_required(VERSION 3.10)
project(testC C)

set(CMAKE_C_STANDARD 99)

add_executable(C-Ladder src/main.c include/numbers.h src/guess/bulls_and_corws.c include/boolean.h include/profile_active.h)