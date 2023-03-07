// source: https://github.com/VictorGordan/opengl-tutorials.git
#ifndef VBO_CLASS_HPP_
#define VBO_CLASS_HPP_
#include <glad/glad.h>
#include <glm/glm.hpp>

namespace graphics {

class VBO {
 public:
  // Constructor that generates a Vertex Buffer Object and links it to vertices
  VBO(GLfloat const* vertices, const GLsizeiptr& size);
  GLuint GetID() const { return ID; }
  // VBO(const std::list<Vertex> &vertices);
  //  Binds the VBO
  void Bind() const;
  // Unbinds the VBO
  void Unbind() const;
  // Deletes the VBO
  void Delete();
  ~VBO() {
    Unbind();
    Delete();
  }

 private:
  // Reference ID of the Vertex Buffer Object
  GLuint ID;
};

}  // namespace graphics

#endif