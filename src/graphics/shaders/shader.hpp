// source: https://github.com/VictorGordan/opengl-tutorials.git
#ifndef SHADER_HPP_
#define SHADER_HPP_

#include <glad/glad.h>

#include <cerrno>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace graphics {

class Shader {
 public:
  // Reference ID of the Shader Program

  // Constructor that build the Shader Program from 2 different shaders
  Shader(const std::string &frag_code, const std::string &vert_code);
  ~Shader() { Delete(); }
  GLuint GetId() const { return ID; }
  // Activates the Shader Program
  void Activate();
  // Deletes the Shader Program
  void Delete();

 private:

  // Checks if the different Shaders have compiled properly
  GLuint ID;
  void compileErrors(unsigned int shader, const char* type);

};

}  //namespace graphics 



#endif  // !SHADER_HPP_
