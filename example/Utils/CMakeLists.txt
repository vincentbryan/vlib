cmake_minimum_required(VERSION 2.8)
project(program_test)

find_package(Threads REQUIRED)

set(VLIB_ROOT ${PROJECT_SOURCE_DIR}/../..)
set(VLIB_PATH ${VLIB_ROOT}/lib)

include_directories(
		${VLIB_ROOT}/include
)


set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_PATH})

add_executable(program_test program_test.cpp program_test.h)

target_link_libraries(program_test Threads::Threads ${VLIB_PATH}/libVLib.so)