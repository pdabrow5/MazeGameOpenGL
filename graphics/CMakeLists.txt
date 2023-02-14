set(HEADERS
        Shape.hpp
        data_buffers/EBO.hpp
        data_buffers/VAO.hpp
        data_buffers/VBO.hpp
        data_buffers/figure_data.hpp
        data_buffers/basic_figure_data.hpp
        shaders/shader.hpp
        shaders/basic_shader.hpp
        figure_data_factories/figure_factory.hpp
        figure_data_factories/basic_figure_factory.hpp
        )
set(SOURCES
        Shape.cpp
        data_buffers/EBO.cpp
        data_buffers/VAO.cpp
        data_buffers/VBO.cpp 
        data_buffers/figure_data.cpp
        data_buffers/basic_figure_data.cpp
        shaders/shader.cpp
        shaders/basic_shader.cpp
        figure_data_factories/figure_factory.cpp
        figure_data_factories/basic_figure_factory.cpp

        )

add_library(graphics ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-windows/share")

#find_path(GLFW3_INCLUDE_DIR NAMES glfw3.h PATH_SUFFIXES GLFW)
#include_directories(${GLFW3_INCLUDE_DIR})
#set(glfw3_DIR "C:src\\vcpkg\\installed\\x86-windows\\share\\glfw3")

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(graphics PUBLIC glfw)

find_package(glad CONFIG REQUIRED)
target_link_libraries(graphics PUBLIC glad::glad)

find_package(glm CONFIG REQUIRED)
target_link_libraries(graphics PUBLIC glm::glm)