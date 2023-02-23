add_subdirectory(graphics)
target_include_directories(graphics
  PUBLIC .)

add_executable (MazeGameOpenGL "MazeGameOpenGL.cpp")

target_link_libraries(MazeGameOpenGL
  graphics
)