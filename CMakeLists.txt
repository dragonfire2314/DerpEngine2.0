cmake_minimum_required (VERSION 3.8)

project(DerpEngine VERSION 0.1.0 DESCRIPTION "DerpEngine interfaces with opengl for use with the derp software suite")

# file(GLOB_RECURSE DERP_ENGINE_SOURCES src/*.cpp)

file(GLOB DERP_ENGINE_SOURCES
     "include/*.h"
     "src/*.cpp"
)

add_library(${PROJECT_NAME} SHARED  
    # ${DERP_ENGINE_SOURCES}
    src/application.cpp
    src/ecs/ComponentManager.cpp
    src/ecs/EntityManager.cpp
    src/ecs/SystemManager.cpp
    src/ecs/Components.cpp
    src/ecs/systems/System.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER include/derpEngine.h)

target_include_directories(${PROJECT_NAME} 
    PUBLIC include
    PUBLIC ${CMAKE_SOURCE_DIR}/ext/glfw/include
    PUBLIC ${CMAKE_SOURCE_DIR}/ext/glew/include
    PUBLIC ${CMAKE_SOURCE_DIR}/ext/glm
)
target_include_directories(${PROJECT_NAME}
    PRIVATE src
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE ext/glfw
    PRIVATE ext/glew
)

target_link_libraries(${PROJECT_NAME} 
    glfw
    glew
)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})