# CMakeList.txt : CMake project for MazeGameOpenGL, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)



project (root)
#add_executable (MazeGameOpenGL "MazeGameOpenGL.cpp")

#add_subdirectory(graphics)
#target_link_libraries(${PROJECT_NAME} graphics)

add_subdirectory(src)

#set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-windows/share")

#find_path(GLFW3_INCLUDE_DIR NAMES glfw3.h PATH_SUFFIXES GLFW)
#include_directories(${GLFW3_INCLUDE_DIR})
#set(glfw3_DIR "C:src\\vcpkg\\installed\\x86-windows\\share\\glfw3")

#find_package(glfw3 CONFIG REQUIRED)
#target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

#find_package(glad CONFIG REQUIRED)
#target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)

#find_package(glm CONFIG REQUIRED)
#target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)
# Add source to this project's executable.


# TODO: Add tests and install targets if needed.
