#include "figure_data.hpp"
#include <stdexcept>
#include <cassert>
#include <string>

namespace graphics {

#define assertm(exp, msg) assert(((void)msg, exp))

FigureData::FigureData(const std::vector<GLfloat>& vertices,
                       const std::vector<GLuint>& indices,
                       const std::vector<GLuint>& data_format) {

  CheckDataFormat(vertices, indices, data_format);
  vao_ = std::make_unique<VAO const>();
  vao_->Bind();
  vbo_ = std::make_unique<VBO const>(vertices.data(), vertices.size() * sizeof(GLfloat));
  ebo_ = std::make_unique<EBO const>(indices.data(), indices.size() * sizeof(GLuint));
  LinkVaoAttrib(vertices, indices, data_format);

  vao_->Unbind();
  vbo_->Unbind();
  ebo_->Unbind();
}

FigureData::FigureData(std::unique_ptr<VertexData> vertex_data,
                       std::unique_ptr<VertexDataChecker> vertex_data_checker) {
  if (!vertex_data_checker->IsDataValid(*vertex_data))
    throw std::invalid_argument("Wrong VertexData format");

  vao_ = std::make_unique<VAO const>();
  vao_->Bind();
  vbo_ = std::make_unique<VBO const>(vertex_data->vertices.data(),
      vertex_data->vertices.size() * sizeof(GLfloat));
  ebo_ = std::make_unique<EBO const>(vertex_data->indices.data(),
      vertex_data->indices.size() * sizeof(GLuint));
  LinkVaoAttrib(vertex_data->vertices, vertex_data->indices,
                vertex_data->data_format);

  vao_->Unbind();
  vbo_->Unbind();
  ebo_->Unbind();

}



void FigureData::CheckVerticesFormat(
    const std::vector<GLfloat>& vertices,
    const std::vector<GLuint>& data_format) const {
  size_t size_of_vertex = 0;
  for (auto& elem : data_format) size_of_vertex += elem;
  assertm(vertices.size() % size_of_vertex == 0,
          ("Vertex data isn't valid: each vertex should consist of " +
           std::to_string(size_of_vertex) + "GLfloat values."));

}

void FigureData::CheckIndicesFormat(const std::vector<GLfloat>& vertices,
                                    const std::vector<GLuint>& indices,
                                    const size_t &size_of_vertex) const {
  assertm(indices.size() % 3 == 0, "Number of indices must be multiple of 3.");

  bool each_set_is_triangle = true;
  for (size_t i = 0; i < indices.size(); i += 3) {
    bool each_set_is_triangle =
        (indices[i] != indices[i + 1] &&
        indices[i] != indices[i + 2] &&
        indices[i + 1] != indices[i + 2]);
      assertm(each_set_is_triangle,
        "Each index in each set of 3 must point other vertex.");
  }

    //if (indices[i] == indices[i + 1] || indices[i] == indices[i + 2] ||
    //    indices[i + 1] == indices[i + 2]) {
    //  each_set_is_triangle = false;
    //  break;
    //}
  

  bool index_in_range = true;
  for (auto& index : indices)
    if (index >= vertices.size() / size_of_vertex) {
      index_in_range = false;
      break;
    }
  assertm(index_in_range, "Index must reffer to vertex.");
}

void FigureData::CheckFormatCorrectness(
    const std::vector<GLuint>& data_format) const {
  for (auto& i : data_format)
    assertm(i != 0, "Each element of data format must be positive.");
}

void FigureData::CheckDataFormat(const std::vector<GLfloat>& vertices,
                                 const std::vector<GLuint>& indices,
                                 const std::vector<GLuint>& data_format) {
  GLuint size_of_vertex = 0;
  for (auto& elem : data_format)
    size_of_vertex += elem;
  CheckFormatCorrectness(data_format);
  CheckIndicesFormat(vertices, indices, size_of_vertex);
  CheckVerticesFormat(vertices, data_format);
  CheckAdditionalRules(vertices, indices);
}


void FigureData::LinkVaoAttrib(const std::vector<GLfloat>& vertices,
                               const std::vector<GLuint>& indices,
                               const std::vector<GLuint>& data_format) const {
  GLuint size = 0;
  for (auto & elem : data_format) size += elem;
  GLuint offset = 0;
  for (size_t i = 0; i < data_format.size(); ++i) {
    vao_->LinkAttrib(*vbo_, i, data_format[i], GL_FLOAT, size * sizeof(float),
                     (void*)(offset * sizeof(float)));
    offset += data_format[i];
  }
}

}  // namespace graphics
