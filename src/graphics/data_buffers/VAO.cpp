// source: https://github.com/VictorGordan/opengl-tutorials.git
#include "VAO.hpp"

// Constructor that generates a VAO ID
VAO::VAO() { glGenVertexArrays(1, &ID); }

// Links a VBO Attribute such as a position or color to the VAO
void VAO::LinkAttrib (const VBO& VBO, GLuint layout, GLuint numComponents, GLenum type,
                     GLsizeiptr stride, void* offset) const {
  VBO.Bind();
  glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
  glEnableVertexAttribArray(layout);
  VBO.Unbind();
}

// Binds the VAO
void VAO::Bind() const { glBindVertexArray(ID); }

// Unbinds the VAO
void VAO::Unbind() const { glBindVertexArray(0); }

// Deletes the VAO
void VAO::Delete() { glDeleteVertexArrays(1, &ID); }