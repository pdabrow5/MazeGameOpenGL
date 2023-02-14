#include "figure_data.hpp"

class BasicFigureData final : public FigureData {
//using FigureData::FigureData;
 public:
  BasicFigureData(const std::vector<GLfloat> &vertices,
                  const std::vector<GLuint> &indices)
      : FigureData(vertices, indices, {3, 3}) {};

 private:
  void CheckAdditionalRules(
      const std::vector<GLfloat> &vertices,
      const std::vector<GLuint> &indices) const override;
};