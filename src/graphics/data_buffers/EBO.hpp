// source: https://github.com/VictorGordan/opengl-tutorials.git
#ifndef EBO_CLASS_HPP_
#define EBO_CLASS_HPP_

#include <glad/glad.h>

namespace graphics {

class EBO {
 public:

  // Constructor that generates a Elements Buffer Object and links it to indices
  EBO(GLuint const* indices, const GLsizeiptr& size);

  // Binds the EBO
  void Bind() const;
  // Unbinds the EBO
  void Unbind() const;    
  // Deletes the EBO
  void Delete();
  unsigned int GetCount() const { return count; }
  GLuint GetID() const { return ID; }
  ~EBO() {
    Unbind();
    Delete();
  }

 private:
  // ID reference of Elements Buffer Object
  GLuint ID;
  unsigned int count;
};

}  //namespace graphics
#endif
