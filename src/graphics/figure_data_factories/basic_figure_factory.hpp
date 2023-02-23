#ifndef BASIC_FIGURE_FACTORY_HPP_
#define BASIC_FIGURE_FACTORY_HPP_

#include "../data_buffers/basic_figure_data.hpp"
#include "../shaders/shader.hpp"
#include "figure_factory.hpp"

class BasicFigureFactory final : public FigureFactory {
 public:
  virtual std::unique_ptr<Shader> MakeShader() const override;
  virtual std::unique_ptr<FigureData> MakeFigureData(
      const std::vector<GLfloat>& vertices,
      const std::vector<GLuint>& indices) const override {
    return std::make_unique<BasicFigureData>(vertices, indices);
  };
};

#endif  // !BASIC_FIGURE_FACTORY_HPP_

