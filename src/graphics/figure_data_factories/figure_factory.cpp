#include "figure_factory.hpp"

namespace graphics {

std::unique_ptr<FigureData> FigureFactory::MakeFigureData2(
    std::unique_ptr<VertexData> vertex_data,
    std::unique_ptr<VertexDataChecker> vertex_data_checker) const {
  return std::make_unique<FigureData>(std::move(vertex_data), std::move(vertex_data_checker));
}

std::unique_ptr<Figure> FigureFactory::MakeFigure(
    std::unique_ptr<VertexData> vertex_data) const {
  return std::make_unique<Figure>(
      std::move(MakeFigureData2(std::move(vertex_data), MakeVertexDataChecker())), MakeShader());
}
std::unique_ptr<Figure> FigureFactory::MakeFigure(
    std::unique_ptr<VertexData> vertex_data,
    std::shared_ptr<Shader> shader) const {
  return std::make_unique<Figure>(
      std::move(MakeFigureData2(std::move(vertex_data), MakeVertexDataChecker())),
      shader);
}

}  //  namespace graphics
