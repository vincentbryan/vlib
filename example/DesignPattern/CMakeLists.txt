cmake_minimum_required(VERSION 2.8)
project(design_pattern_test)

find_package(Threads REQUIRED)

set(VLIB_ROOT ${PROJECT_SOURCE_DIR}/../..)
set(BIN_OUTPUT_PATH ${VLIB_ROOT}/bin/DesignPattern)
set(VLIB_PATH ${VLIB_ROOT}/lib)

include_directories(
		${VLIB_ROOT}/include
		${VLIB_ROOT}/include/DesignPattern
		${VLIB_ROOT}/include/Template
		${VLIB_ROOT}/include/Thread
)


set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_PATH})

add_executable(singleton_test singleton_test.cpp)
add_executable(observer_test  observer_test.cpp)

target_link_libraries(singleton_test Threads::Threads ${VLIB_PATH}/libVLib.so)
target_link_libraries(observer_test  Threads::Threads ${VLIB_PATH}/libVLib.so)