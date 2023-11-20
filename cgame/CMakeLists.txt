project(cgame)

add_library(${PROJECT_NAME} SHARED 
game.c
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC clib cengine)