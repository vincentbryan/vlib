cmake_minimum_required(VERSION 2.8)

project(VLib)

set(CMAKE_CXX_FLAGS "-std=c++11")

set(VLIB_ROOT ${PROJECT_SOURCE_DIR}/..)
set(LIBRARY_OUTPUT_PATH ${VLIB_ROOT}/lib)
set(BIN_OUTPUT_PATH, ${VLIB_ROOT}/bin)

include_directories(
        ${VLIB_ROOT}/include
        ${VLIB_ROOT}/include/DesignPattern
        ${VLIB_ROOT}/include/Thread
        ${VLIB_ROOT}/include/Template
		${VLIB_ROOT}/include/Utils
		${VLIB_ROOT}/include/UI
)

aux_source_directory(Utils/ VLIB_SRC)
aux_source_directory(UI/ VLIB_SRC)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_PATH})

add_compile_options("-fpermissive")

add_library(
        ${PROJECT_NAME} SHARED
        ${VLIB_SRC}
)

#target_link_libraries(${PROJECT_NAME})