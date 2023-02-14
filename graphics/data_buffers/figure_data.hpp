#ifndef FIGURE_DATA_CLASS_HPP_
#define FIGURE_DATA_CLASS_HPP_

#include "EBO.hpp"
#include "VBO.hpp"
#include "VAO.hpp"

#include <memory>
#include <vector>

class FigureData {
 public:
  FigureData(const std::vector<GLfloat> &vertices,
             const std::vector<GLuint> &indices,
             const std::vector<GLuint> &data_format);

  void BindVao() const { vao_->Bind();}

  void CheckDataFormat(const std::vector<GLfloat> &vertices,
                      const std::vector<GLuint> &indices,
                      const std::vector<GLuint> &data_format);
  unsigned int FigureData::GetEBOCount() const { return ebo_->GetCount(); }

 private:
  std::unique_ptr<EBO const> ebo_;
  std::unique_ptr<VAO const> vao_;
  std::unique_ptr<VBO const> vbo_;


  void CheckVerticesFormat(const std::vector<GLfloat> &vertices,
                            const std::vector<GLuint> &data_format) const;

  void CheckIndicesFormat(const std::vector<GLfloat> &vertices,
                          const std::vector<GLuint> &indices,
                          const size_t &size_of_vertex) const;

  void CheckFormatCorrectness(const std::vector<GLuint> &data_format) const;

  virtual void CheckAdditionalRules(
      const std::vector<GLfloat> &vertices, 
      const std::vector<GLuint> &indices) const = 0;

  void LinkVaoAttrib(const std::vector<GLfloat> &vertices,
                     const std::vector<GLuint> &indices,
                     const std::vector<GLuint> &data_format) const;

};


#endif  // !FIGURE_DATA_CLASS_HPP_
