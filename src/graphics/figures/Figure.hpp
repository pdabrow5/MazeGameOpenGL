#ifndef FIGURE_HPP_
#define FIGURE_HPP_

#include "../data_buffers/figure_data.hpp"
#include "../shaders/shader.hpp"

namespace graphics {

class Figure {
 public:
  Figure(std::shared_ptr<FigureData> figure_data,
         std::shared_ptr<Shader> shader);
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

}  // namespace graphics


#endif  // !FIGURE_HPP_
