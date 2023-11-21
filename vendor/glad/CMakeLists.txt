project(glad)

add_library(${PROJECT_NAME} SHARED 
include/glad/gl.h
src/gl.c
)

target_include_directories(glad PUBLIC include/)