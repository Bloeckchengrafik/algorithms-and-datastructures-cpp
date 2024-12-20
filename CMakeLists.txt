cmake_minimum_required(VERSION 3.29)
project(aud)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)

file(GLOB_RECURSE SOURCES_TREES "trees/*.cpp")
file(GLOB_RECURSE SOURCES_TREES_H "trees/*.h")

add_executable(trees ${SOURCES_TREES} ${SOURCES_TREES_H})
