project(cengine)

add_library(${PROJECT_NAME} SHARED 
graphics/window.c
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC clib SDL3::SDL3)