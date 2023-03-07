#include "basic_vertex_data_checker.hpp"


namespace graphics {

bool BasicVertexDataChecker::AreIndicesValid(
    const VertexData &vertex_data) const {
  if(vertex_data.indices.size() % 3 == 0) return false;

  for (size_t i = 0; i < vertex_data.indices.size(); i += 3)
    if (vertex_data.indices[i] == vertex_data.indices[i + 1] ||
        vertex_data.indices[i] == vertex_data.indices[i + 2] ||
        vertex_data.indices[i + 1] == vertex_data.indices[i + 2])
      return false;
  GLuint number_of_vertices = vertex_data.vertices.size() / std::accumulate(vertex_data.data_format.begin(),
      vertex_data.data_format.end(), 0);
  for (auto &index : vertex_data.indices)
    if (index >= number_of_vertices) return false;

  return true;
}

bool BasicVertexDataChecker::AreVerticesValid(
    const VertexData &vertex_data) const {
  size_t size_of_vertex = std::accumulate(vertex_data.data_format.begin(),
      vertex_data.data_format.end(), 0);
  return vertex_data.vertices.size() % size_of_vertex == 0;
}

}  //  namespace graphics