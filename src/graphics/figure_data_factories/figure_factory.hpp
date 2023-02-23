#ifndef FIGURE_FACTORY_HPP_
#define FIGURE_FACTORY_HPP_

#include "../data_buffers/figure_data.hpp"
#include "../shaders/shader.hpp"

class FigureFactory {
 public:
  virtual std::unique_ptr<Shader> MakeShader() const = 0;
  virtual std::unique_ptr<FigureData> MakeFigureData(
      const std::vector<GLfloat> &vertices,
      const std::vector<GLuint> &indices) const = 0;
};

#endif  // !FIGURE_FACTORY_HPP_
