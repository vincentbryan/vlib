cmake_minimum_required(VERSION 3.9)
project(vlib)

find_package(Threads REQUIRED)

set(VLIB_ROOT ${PROJECT_SOURCE_DIR})

include_directories(
        ${VLIB_ROOT}/include
		${VLIB_ROOT}/3rd/Eigen/include
)


set(CMAKE_CXX_STANDARD 11)

add_executable(vlib main.cpp)

target_link_libraries(vlib
		Threads::Threads
)

add_subdirectory(./src)
add_subdirectory(./example)