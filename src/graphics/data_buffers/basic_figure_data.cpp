#include "basic_figure_data.hpp"
#include <iostream>

namespace graphics {
#define assertm(exp, msg) assert(((void)msg, exp))

void BasicFigureData::CheckAdditionalRules(
    const std::vector<GLfloat>& vertices,
    const std::vector<GLuint>& indices) const {
  std::cout << "sprawdzone\n";
  for(size_t vertex = 0; vertex < vertices.size(); vertex += 6) {
    assertm(vertices[vertex + 3] >= 0 && vertices[vertex + 3] <= 1, "Each from RGB values should be in 0:1.");
    assertm(vertices[vertex + 4] >= 0 && vertices[vertex + 4] <= 1,"Each from RGB values should be in 0:1.");
    assertm(vertices[vertex + 5] >= 0 && vertices[vertex + 5] <= 1, "Each from RGB values should be in 0:1.");
  }
}


}  // namespace graphics
