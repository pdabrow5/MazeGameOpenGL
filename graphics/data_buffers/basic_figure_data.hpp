#include "figure_data.hpp"

class BasicFigureData final : public FigureData {
  using FigureData::FigureData;
  void CheckAdditionalRules(
      const std::vector<GLfloat> &vertices,
      const std::vector<GLuint> &indices) const override;
};