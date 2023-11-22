project(cengine)

add_library(${PROJECT_NAME} SHARED 
graphics/window.c
graphics/shader.c
graphics/renderer.c
engine.c
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC clib SDL2::SDL2 glad)