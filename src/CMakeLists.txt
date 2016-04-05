set(HEADER_FILES ${CMAKE_SOURCE_DIR}/include)
include_directories(${HEADER_FILES})

set(SOURCE_FILES main.cpp
        ${HEADER_FILES}/scene.h scene.cpp
        ${HEADER_FILES}/drawable.h drawable.cpp
        ${HEADER_FILES}/camera.h
        ${HEADER_FILES}/ortho_camera.h ortho_camera.cpp
        ${HEADER_FILES}/geometry.h geometry.cpp
        ${HEADER_FILES}/gizmo.h gizmo.cpp
        ${HEADER_FILES}/program.h program.cpp
        ${HEADER_FILES}/mvp_simple_color_program.h mvp_simple_color_program.cpp
        ${HEADER_FILES}/mvp_program.h mvp_program.cpp
        ${HEADER_FILES}/regular_polygon.h regular_polygon.cpp)

add_executable(hello_opengl ${SOURCE_FILES})
target_link_libraries(hello_opengl ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})

add_subdirectory(shaders)
