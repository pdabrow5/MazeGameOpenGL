#include "../data_buffers/figure_data.hpp"
#include "../shaders/shader.hpp"

class FigureFactory {
  virtual Shader *MakeShader() const = 0;
  virtual FigureData *MakeFigureData(
      const std::vector<GLfloat> &vertices,
      const std::vector<GLuint> &indices) const = 0;
};