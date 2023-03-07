#ifndef BASIC_VERTEX_DATA_CHECKER_HPP_
#define BASIC_VERTEX_DATA_CHECKER_HPP_

#include "vertex_data_checker.hpp"
#include <numeric>

namespace graphics {

class BasicVertexDataChecker : public VertexDataChecker {
 
  bool AreIndicesValid(const VertexData &vertex_data) const override;
  bool AreVerticesValid(const VertexData &vertex_data) const override;
};


}  // namespace graphics

#endif  // !BASIC_VERTEX_DATA_CHECKER_HPP_


