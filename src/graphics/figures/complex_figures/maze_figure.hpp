#ifndef MAZE_FIGURE_HPP_
#define MAZE_FIGURE_HPP_


#include "../figure.hpp"
#include "state_figure.hpp"
#include <vector>

namespace graphics {

class MazeLayout {
 public:
  enum class MazeCellType { path, wall };
  MazeLayout(const std::vector<std::vector<MazeCellType>> &layout)
      : layout_(layout) {}

  MazeLayout(size_t height, size_t width){
      layout_ = std::vector<std::vector<MazeCellType>>(
      height, std::vector<MazeCellType>(width, MazeCellType::wall));
}

  bool IsPath(size_t row, size_t column) const {
    return layout_[row][column] == MazeCellType::path;
  } 
  size_t size() const{ return layout_.size(); }
  std::vector<glm::vec3> GetWallsCoordinates(GLfloat check_pattern_size) const;
  std::vector<std::vector<MazeCellType>>::iterator begin() {return layout_.begin();}
  std::vector<std::vector<MazeCellType>>::const_iterator cbegin() const {return layout_.cbegin();}
  std::vector<std::vector<MazeCellType>>::iterator end() {return layout_.end();}
  std::vector<std::vector<MazeCellType>>::const_iterator cend() const {return layout_.cend();}
  std::vector<MazeCellType> &operator[](std::size_t idx) { return layout_[idx]; }
  const std::vector<MazeCellType> &operator[](std::size_t idx) const { return layout_[idx]; }
  
 private:
  std::vector<std::vector<MazeCellType>> layout_;
};


class MazeFigure : public StateFigure {
 public:
  using StateFigure::StateFigure;
  struct MoveSettings {
    GLfloat step;
    GLfloat vel;
    GLfloat acc;
  };
  enum class MazeState {steady, appear, disappear };
  MazeFigure(std::unique_ptr<Figure> figure, MoveSettings settings);
  bool TriggerMove(MazeState state){};
  void Act() override;

 private:
  MazeState maze_state_ = MazeState::steady;
  MoveSettings move_settings_;

};

}  // namespace graphics
#endif  // !MAZE_FIGURE_HPP_
