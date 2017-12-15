cmake_minimum_required(VERSION 3.8)
project(OS_proj)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Opcodes.h Opfunction.h Opfunction.cpp Registers.h CPU_info.h CPU.cpp)
add_executable(OS_proj ${SOURCE_FILES})