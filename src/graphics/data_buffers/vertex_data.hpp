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
      : vertices(vert), indices(ind), data_format(data_form) {
    std::cout << "r_val constructor called \n";
  }

  ~VertexData() {
    std::cout << "VERTEX DATA DELETED, SIZE: " << vertices.size() << std::endl;
  }


  std::vector<GLfloat> vertices;
  std::vector<GLuint> indices;
  std::vector<GLuint> data_format;
};
}  // namespace graphics

#endif  // !VERTEX_DATA_HPP_

