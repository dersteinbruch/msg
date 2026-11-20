cmake_minimum_required(VERSION 4.3.0)

project(msg)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_PREFIX_PATH ./lib/boost_1_92_0/stage/lib/cmake)

find_package(Boost REQUIRED)

add_subdirectory(src)
