#ifndef FIGURE_DATA_FACTORY_HPP_
#define FIGURE_DATA_FACTORY_HPP_

#include "../data_buffers/figure_data.hpp"
#include "../shaders/shader.hpp"
#include "../figures/figure.hpp"
#include "../data_buffers/vertex_data.hpp"
#include "../data_buffers/vertex_data_checkers/vertex_data_checker.hpp"

namespace graphics {

class FigureFactory {
 public:
  virtual std::unique_ptr<Shader> MakeShader() const = 0;
  virtual std::unique_ptr<VertexDataChecker> MakeVertexDataChecker() const = 0;

  virtual std::unique_ptr<FigureData> MakeFigureData(
      const std::vector<GLfloat> &vertices,
      const std::vector<GLuint> &indices) const = 0;
  

  std::unique_ptr<FigureData> MakeFigureData2(
      std::unique_ptr<VertexData> vertex_data,
      std::unique_ptr<VertexDataChecker> vertex_data_checker) const;

  std::unique_ptr<Figure> MakeFigure(
      std::unique_ptr<VertexData> vertex_data) const;

  std::unique_ptr<Figure> MakeFigure(
      std::unique_ptr<VertexData> vertex_data,
      std::shared_ptr<Shader> shader) const;

  virtual std::unique_ptr<VertexData> MakeRectangle(
      const glm::vec2 &dimensions,
      const glm::vec3 &color) const = 0;

  virtual std::unique_ptr<VertexData> MakeCuboid(
      const glm::vec3 &dimensions,
      const glm::vec3 &color) const = 0;

  virtual std::unique_ptr<VertexData> MakeShadedCuboid(
      const glm::vec3 &dimensions,
      const glm::vec3 &color,
      const glm::vec2 &shading_level) const = 0;

  virtual std::unique_ptr<VertexData> MakeDetailedCuboid(
      const glm::vec3 &dimensions,
      const glm::vec3 &main_color,
      const glm::vec3 &details_color) const = 0;

  virtual std::unique_ptr<VertexData> MakeMazeFigure(
      const std::vector<glm::vec3> &walls_coordinates,
      std::unique_ptr<const VertexData> wall_pattern) const = 0;
};

}  // namespace graphics



#endif  // !FIGURE_DATA_FACTORY_HPP_
