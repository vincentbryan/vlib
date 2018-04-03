cmake_minimum_required(VERSION 2.8)
project(syncqueue_test)

find_package(Threads REQUIRED)

set(VLIB_ROOT ${PROJECT_SOURCE_DIR}/../..)
set(BIN_OUTPUT_PATH ${VLIB_ROOT}/bin/Thread)
set(VLIB_PATH ${VLIB_ROOT}/lib)

include_directories(
		${VLIB_ROOT}/include
		${VLIB_ROOT}/include/DesignPattern
		${VLIB_ROOT}/include/Template
		${VLIB_ROOT}/include/Thread
)


set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_PATH})

add_executable(${PROJECT_NAME} syncqueue_test.cpp)


target_link_libraries(${PROJECT_NAME} Threads::Threads ${VLIB_PATH}/libVLib.so)