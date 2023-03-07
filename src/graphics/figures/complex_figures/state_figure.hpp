#include "../figure.hpp"

namespace graphics {

class StateFigure {
 public:
  StateFigure(std::unique_ptr<Figure> figure) : figure_(std::move(figure)) {
    position_ = figure_->GetPosition();
    pose_ = figure_->GetPose();
  }
  virtual void Act() = 0;
  void Show() const {figure_->Show();}
  void Move(const glm::vec3 &vec) {position_ += vec; figure_->SetPosition(position_);}
  void SetPosition(const glm::vec3 &vec) {position_ = vec; figure_->SetPosition(position_);}
  void Rotate(const glm::vec3 &vec) {figure_->Rotate(vec); pose_ = figure_->GetPose();}
  void SetPose(const glm::vec3 &vec) {pose_ = vec; figure_->SetPose(pose_);}
 protected:
  std::unique_ptr<Figure> figure_;
  glm::vec3 position_;
  glm::vec3 pose_;
};


}  // namespace graphics

