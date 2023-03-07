#ifndef BASIC_FIGURE_FACTORY_HPP_
#define BASIC_FIGURE_FACTORY_HPP_

#include "../data_buffers/basic_figure_data.hpp"
#include "../shaders/shader.hpp"
#include "figure_factory.hpp"

namespace graphics {

class BasicFigureFactory final : public FigureFactory {
 public:
  BasicFigureFactory() { shader_ = MakeShader(); }
  virtual std::unique_ptr<Shader> MakeShader() const override;
  virtual std::unique_ptr<VertexDataChecker> MakeVertexDataChecker()
      const override;

  virtual std::unique_ptr<FigureData> MakeFigureData(
      const std::vector<GLfloat>& vertices,
      const std::vector<GLuint>& indices) const override {
    return std::make_unique<BasicFigureData>(vertices, indices);
  };


  virtual std::unique_ptr<VertexData> MakeRectangle(
      const glm::vec2 &dimensions,
      const glm::vec3 &color) const override;

  virtual std::unique_ptr<VertexData> MakeCuboid(
      const glm::vec3 &dimensions,
      const glm::vec3 &color) const override;

  virtual std::unique_ptr<VertexData> MakeShadedCuboid(
      const glm::vec3 &dimensions,
      const glm::vec3 &color,
      const glm::vec2 &shading_level) const override;

  virtual std::unique_ptr<VertexData> MakeDetailedCuboid(
      const glm::vec3 &dimensions,
      const glm::vec3 &vertex_color,
      const glm::vec3 &inner_color) const override;

  virtual std::unique_ptr<VertexData> MakeMazeFigure(
      const std::vector<glm::vec3> &walls_coordinates,
      std::unique_ptr<VertexData> wall_pattern) const override;


 private:
  std::shared_ptr<Shader> shader_;
};

}  // namespace graphics



#endif  // !BASIC_FIGURE_FACTORY_HPP_

