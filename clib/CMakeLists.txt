project(clib)

add_library(${PROJECT_NAME} SHARED 
logger.c
list.c
named_list.c
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})