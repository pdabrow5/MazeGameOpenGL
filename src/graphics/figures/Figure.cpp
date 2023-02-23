#include "Figure.hpp"
#include "glm/gtx/euler_angles.hpp"
#include "glm/gtc/type_ptr.hpp"

Figure::Figure(const FigureFactory& factory,
               const std::vector<GLfloat>& vertices,
               const std::vector<GLuint>& indices) {
  figure_data_ = std::move(factory.MakeFigureData(vertices, indices));
  shader_ = std::move(factory.MakeShader());

  mvp_.model = glm::rotate(glm::mat4(1.0f), 0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
  mvp_.view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

  GLfloat fovy(45.0f), aspect(1.0f), near(0.1f), far(100.0f);  
  mvp_.proj = glm::perspective(glm::radians(fovy), aspect, near, far);


}

void Figure::Move(const glm::vec3& vec) {
  mvp_.view = glm::translate(mvp_.view, vec);
}

void Figure::Rotate(const glm::vec3& vec) {
  mvp_.model = mvp_.model * glm::eulerAngleXYZ(vec.x, vec.y, vec.z);
}

void Figure::SetPosition(const glm::vec3& vec) {
  mvp_.view = glm::translate(glm::mat4(1.0f), vec);
}

void Figure::SetPose(const glm::vec3& vec) {
  mvp_.model = glm::eulerAngleXYZ(vec.x, vec.y, vec.z);
}

glm::vec3 Figure::GetPose() const {
  glm::vec3 pose;
  glm::extractEulerAngleXYZ(mvp_.model, pose.x, pose.y, pose.z);
  return pose;
}

glm::vec3 Figure::GetPosition() const { 
    return glm::vec3(); }

void Figure::Show() const {
  shader_->Activate();
  GLuint shader_id = shader_->GetId();

  int uniID = glGetUniformLocation(shader_id, "scale");
  int modelLoc = glGetUniformLocation(shader_id, "model");
  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(mvp_.model));
  int viewLoc = glGetUniformLocation(shader_id, "view");
  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(mvp_.view));
  int projLoc = glGetUniformLocation(shader_id, "proj");
  glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(mvp_.proj));
  glUniform1f(uniID, 1.0f);

  figure_data_->BindVao();
  glDrawElements(GL_TRIANGLES, figure_data_->GetEBOCount(), GL_UNSIGNED_INT, 0);
}
