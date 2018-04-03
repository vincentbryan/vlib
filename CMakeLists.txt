cmake_minimum_required(VERSION 3.9)
project(vlib)


find_package(Threads REQUIRED)

set(VLIB_ROOT ${PROJECT_SOURCE_DIR})
include_directories(
        ${VLIB_ROOT}/include
)


set(CMAKE_CXX_STANDARD 11)

add_executable(vlib main.cpp include/Thread/Threads.h include/macro.h include/Timer.h include/Thread/SyncQueue.hpp include/vlib.h)

target_link_libraries(vlib Threads::Threads)