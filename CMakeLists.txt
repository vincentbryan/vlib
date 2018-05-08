cmake_minimum_required(VERSION 3.9)
project(main)

find_package(Threads REQUIRED)
find_package(OpenGL REQUIRED)

if (${OPENGL_FOUND})
	message("OPENGL FOUND")
endif ()


add_compile_options(-lgl)
add_compile_options(-Wall)

set(VLIB_ROOT ${PROJECT_SOURCE_DIR})

include_directories(
		${OPENGL_INCLUDE_DIR}
		${VLIB_ROOT}/3rd/Pangolin/include
		${VLIB_ROOT}/include
)


set(CMAKE_CXX_STANDARD 11)
add_executable(main main.cpp)

target_link_libraries(main
		Threads::Threads
		${OPENGL_LIBRARIES}
		${VLIB_ROOT}/lib/libVLib.so
		${PROJECT_SOURCE_DIR}/3rd/Pangolin/lib/libpangolin.so
)

add_subdirectory(./src)
add_subdirectory(./example)