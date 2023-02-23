// source: https://github.com/VictorGordan/opengl-tutorials.git
#include "shader.hpp"

#include <filesystem>
#include <stdexcept>
#include <string>

// Constructor that build the Shader Program from 2 different shaders
Shader::Shader(const std::string& frag_code, const std::string& vert_code) {
  // Convert the shader source strings into character arrays
  const char* vertexSource = vert_code.data();
  const char* fragmentSource = frag_code.data();

  // Create Vertex Shader Object and get its reference
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  // Attach Vertex Shader source to the Vertex Shader Object
  glShaderSource(vertexShader, 1, &vertexSource, NULL);
  // Compile the Vertex Shader into machine code
  glCompileShader(vertexShader);
  // Checks if Shader compiled succesfully
  compileErrors(vertexShader, "VERTEX");

  // Create Fragment Shader Object and get its reference
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  // Attach Fragment Shader source to the Fragment Shader Object
  glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
  // Compile the Vertex Shader into machine code
  glCompileShader(fragmentShader);
  // Checks if Shader compiled succesfully
  compileErrors(fragmentShader, "FRAGMENT");

  // Create Shader Program Object and get its reference
  ID = glCreateProgram();
  // Attach the Vertex and Fragment Shaders to the Shader Program
  glAttachShader(ID, vertexShader);
  glAttachShader(ID, fragmentShader);
  // Wrap-up/Link all the shaders together into the Shader Program
  glLinkProgram(ID);
  // Checks if Shaders linked succesfully
  compileErrors(ID, "PROGRAM");

  // Delete the now useless Vertex and Fragment Shader objects
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

// Activates the Shader Program
void Shader::Activate() { glUseProgram(ID); }

// Deletes the Shader Program
void Shader::Delete() { glDeleteProgram(ID); }

// Checks if the different Shaders have compiled properly
void Shader::compileErrors(unsigned int shader, const char* type) {
  // Stores status of compilation
  GLint hasCompiled;
  // Character array to store error message in
  char infoLog[1024];
  if (type != "PROGRAM") {
    glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
    if (hasCompiled == GL_FALSE) {
      glGetShaderInfoLog(shader, 1024, NULL, infoLog);
      std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n"
                << infoLog << std::endl;
    }
  } else {
    glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
    if (hasCompiled == GL_FALSE) {
      glGetProgramInfoLog(shader, 1024, NULL, infoLog);
      std::cout << "SHADER_LINKING_ERROR for:" << type << "\n"
                << infoLog << std::endl;
    }
  }
}