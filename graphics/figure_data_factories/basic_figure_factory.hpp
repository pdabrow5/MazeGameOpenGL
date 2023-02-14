#include "figure_factory.hpp"
#include "../shaders/basic_shader.hpp"
#include "../data_buffers/basic_figure_data.hpp"

class BasicFigureFactory final : public FigureFactory {
  Shader* MakeShader() const override { return new BasicShader; }
  FigureData* MakeFigureData(
      const std::vector<GLfloat>& vertices,
      const std::vector<GLuint>& indices) const override {
    return new BasicFigureData(vertices, indices, {3, 3});
  };
};