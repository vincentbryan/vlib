cmake_minimum_required(VERSION 2.8)
project(pangolin_test)

find_package(Threads REQUIRED)
find_package(OpenGL REQUIRED)

if (${OPENGL_FOUND})
	message("OPENGL FOUND")
endif ()

add_compile_options(-lgl)
add_compile_options(-Wall)

set(VLIB_ROOT ${PROJECT_SOURCE_DIR}/../..)
set(VLIB_PATH ${VLIB_ROOT}/lib)

include_directories(
		${VLIB_ROOT}/include
		${VLIB_ROOT}/3rd/Pangolin/include
		${OPENGL_INCLUDE_DIRS}
)


set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_PATH})

add_executable(pangolin_test pangolin_test.cpp)

target_link_libraries(pangolin_test
		Threads::Threads
		${OPENGL_LIBRARIES}
		${VLIB_ROOT}/3rd/Pangolin/lib/libpangolin.so
		${VLIB_PATH}/libVLib.so
)