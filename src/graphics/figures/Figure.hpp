#ifndef FIGURE_HPP_
#define FIGURE_HPP_

#include "../figure_data_factories/basic_figure_factory.hpp"

class Figure {
 public:
  Figure(const FigureFactory &factory, 
         const std::vector<GLfloat> &vertices,
         const std::vector<GLuint> &indices);
  void Move(const glm::vec3 &vec);
  void Rotate(const glm::vec3 &vec);
  void SetPosition(const glm::vec3 &vec);
  void SetPose(const glm::vec3 &vec);
  glm::vec3 GetPose() const;
  glm::vec3 GetPosition() const;
  void Show() const;
 private:
  std::shared_ptr<FigureData> figure_data_;
  std::shared_ptr<Shader> shader_;
  struct MVP {
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 proj;
  } mvp_;
};
#endif  // !FIGURE_HPP_
