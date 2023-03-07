// source: https://github.com/VictorGordan/opengl-tutorials.git
#ifndef VAO_CLASS_HPP_
#define VAO_CLASS_HPP_

#include <glad/glad.h>

#include "VBO.hpp"

namespace graphics {

class VAO {
 public:
  // Constructor that generates a VAO ID
  VAO();
  GLuint GetID() const { return ID; }
  // Links a VBO Attribute such as a position or color to the VAO
  void LinkAttrib(const VBO& VBO, GLuint layout, GLuint numComponents, GLenum type,
                  GLsizeiptr stride, void* offset) const;
  // Binds the VAO
  void Bind() const;
  // Unbinds the VAO
  void Unbind() const;
  // Deletes the VAO
  void Delete();
  ~VAO() {
    Unbind();
    Delete();
  }

  private:
  // ID reference for the Vertex Array Object
  GLuint ID;
};

}  // namespace graphics

#endif