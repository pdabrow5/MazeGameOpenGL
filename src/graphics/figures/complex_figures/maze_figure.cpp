#include "maze_figure.hpp"

namespace graphics{

std::vector<glm::vec3> MazeLayout::GetWallsCoordinates(
    GLfloat check_pattern_size) const {
  std::vector<glm::vec3> walls_coordinates;
  size_t height = layout_.size();
  size_t width = layout_[0].size();
  for (size_t row = 0; row != height; ++row)
    for (size_t column = 0; column != width; ++column)
      if (!IsPath(row, column)) 
         walls_coordinates.push_back(glm::vec3(column*check_pattern_size, row*check_pattern_size, 0.0f));
  return walls_coordinates;
}

void MazeFigure::Act() {
}

MazeFigure::MazeFigure(std::unique_ptr<Figure> figure, MoveSettings settings)
    : StateFigure(std::move(figure)), move_settings_(settings) {}

}  // namespace graphics



