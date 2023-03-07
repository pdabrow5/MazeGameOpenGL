#ifndef VERTEX_DATA_CHECKER_HPP_
#define VERTEX_DATA_CHECKER_HPP_

#include "../vertex_data.hpp"

namespace graphics {

class VertexDataChecker {
 public:
  virtual bool AreIndicesValid(const VertexData &vertex_data) const;
  virtual bool AreVerticesValid(const VertexData &vertex_data) const;
  virtual bool IsDataFormatValid(const VertexData &vertex_data) const {
    for (auto &n : vertex_data.data_format)
      if (n == 0) return false;
    return true;
  }
  virtual bool CheckAdditionalRules(const VertexData &vertex_data) const {return true;}
  bool IsDataValid(const VertexData &vertex_data) const {
    return AreIndicesValid(vertex_data) && AreVerticesValid(vertex_data) &&
           IsDataFormatValid(vertex_data) && CheckAdditionalRules(vertex_data);
  };
};

} // namespace graphics

#endif  // !VERTEX_DATA_CHECKER_HPP_

