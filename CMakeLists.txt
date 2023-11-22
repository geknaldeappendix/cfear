cmake_minimum_required(VERSION 3.10)

project(cfear)

include_directories(clib cengine cgame)
add_subdirectory(clib)
add_subdirectory(cengine)
add_subdirectory(cgame)
add_subdirectory(vendor/SDL)
add_subdirectory(vendor/glad)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

add_executable(cfear main.c)

target_link_libraries(cfear clib cengine cgame SDL2::SDL2 glad)