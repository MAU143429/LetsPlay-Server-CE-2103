cmake_minimum_required(VERSION 3.17)
project(Let_s_Play_Server)

set(CMAKE_CXX_STANDARD 14)

add_executable(Let_s_Play_Server main.cpp src/Server.cpp src/Server.h)