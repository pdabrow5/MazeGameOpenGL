add_subdirectory(graphics)
target_include_directories(graphics PUBLIC .)


add_executable (MazeGameOpenGL "MazeGameOpenGL.cpp")


set(CMAKE_PREFIX_PATH "C:/src/vcpkg/installed/x64-windows/share")

#find_package(glad CONFIG REQUIRED)
#target_link_libraries(MazeGameOpenGL PUBLIC glad::glad)

#find_package(glm CONFIG REQUIRED)
#target_link_libraries(MazeGameOpenGL PUBLIC glm::glm)

#find_package(glfw3 CONFIG REQUIRED)
#target_link_libraries(MazeGameOpenGL PUBLIC glfw)


target_link_libraries(MazeGameOpenGL
  PUBLIC
  graphics
)