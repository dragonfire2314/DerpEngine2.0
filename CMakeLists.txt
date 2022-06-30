cmake_minimum_required (VERSION 3.8)

project(DerpEngine VERSION 0.1.0 DESCRIPTION "DerpEngine interfaces with opengl for use with the derp software suite")

add_library(${PROJECT_NAME} SHARED 
    src/main.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER include/derpEngine.h)

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_include_directories(${PROJECT_NAME} PRIVATE src)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})