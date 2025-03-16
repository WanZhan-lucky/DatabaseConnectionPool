cmake_minimum_required(VERSION 3.0)

project(ConnectionPool)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)
# 生成debug版本，可以进行gdb调试
# set(CMAKE_BUILD_TYPE "Debug")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/src/include)
link_directories(/user/lib64/mysql)

add_subdirectory(src)