cmake_minimum_required(VERSION 3.8)
project(socket)

set(CMAKE_CXX_STANDARD 11)
# glog
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(Glog)
# gtest
add_subdirectory(googletest)
# exe include
include_directories(${GLOG_INCLUDE_DIRS})
# exe
set(SOURCE_FILES src/main.cpp)
add_executable(socket ${SOURCE_FILES})

