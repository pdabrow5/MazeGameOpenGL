#ifndef VERTEX_DATA_HPP_
#define VERTEX_DATA_HPP_

#include <memory>
#include <vector>
//#include <glm/glm.hpp>
#include <glad/glad.h>
#include <iostream>

namespace graphics {

struct VertexData {
 public:
  VertexData(const std::vector<GLfloat>& vert, const std::vector<GLuint>& ind,
             const std::vector<GLuint>& data_form)
      : vertices(vert), indices(ind), data_format(data_form) {}

  VertexData(std::vector<GLfloat>&& vert, std::vector<GLuint>&& ind,
             std::vector<GLuint>&& data_form)
      : vertices(std::move(vert)), indices(std::move(ind)), data_format(std::move(data_form)) {}


  std::vector<GLfloat> vertices;
  std::vector<GLuint> indices;
  std::vector<GLuint> data_format;
};
}  // namespace graphics

#endif  // !VERTEX_DATA_HPP_

