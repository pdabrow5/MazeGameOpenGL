#include "basic_figure_factory.hpp"
namespace graphics {

std::unique_ptr<Shader> BasicFigureFactory::MakeShader() const {

    std::string vert_code = 
        "#version 330 core\n"
        ""
        "layout(location = 0) in vec3 aPos;\n"
        "layout(location = 1) in vec3 aColor;\n"
        ""
        "out vec3 color;\n"
        "uniform float scale;\n"
        ""
        "uniform mat4 model;\n"
        "uniform mat4 view;\n"
        "uniform mat4 proj;\n"
        ""
        "void main() {\n"
        "  gl_Position = proj * view * model * vec4(aPos, 1.0);\n"
        "  color = aColor;\n"
        "}\n";

  
std::string frag_code = 
        "#version 330 core\n"
        ""
        "out vec4 FragColor;\n"
        "in vec3 color;\n"
        ""
        "void main()\n"
        "{\n"
        "  FragColor = vec4(color, 1.0f);\n"
        "}\n";
    return std::make_unique<Shader>(frag_code, vert_code);
}

std::unique_ptr<VertexDataChecker> BasicFigureFactory::MakeVertexDataChecker()
    const {
  return std::make_unique<VertexDataChecker>();
}

std::unique_ptr<VertexData> BasicFigureFactory::MakeRectangle(
    const glm::vec2 &dimensions, const glm::vec3 &color) const {

  GLfloat x(dimensions.x), y(dimensions.y);

  std::vector<GLfloat> vertices{
      -0.5f * x, -0.5f * y, 0.0f, color.x, color.y, color.z,  // Lower left corner

      -0.5f * x, 0.5f * y, 0.0f, color.x, color.y, color.z,  // Upper left corner

      0.5f * x, 0.5f * y, 0.0f, color.x, color.y, color.z,  // Upper right corner

      0.5f * x, -0.5f * y, 0.0f, color.x, color.y, color.z,  // Lower right corner
  };


  std::vector<GLuint> indices{
      0, 1, 2, 0, 3, 2};

  std::vector<GLuint> data_format
  {3,3};

  return std::make_unique<VertexData>(std::move(vertices), std::move(indices), std::move(data_format));
}

std::unique_ptr<VertexData> BasicFigureFactory::MakeCuboid(
    const glm::vec3 &dimensions, const glm::vec3 &color) const {

  GLfloat x(dimensions.x), y(dimensions.y), z(dimensions.z);

  std::vector<GLfloat> vertices{
      // FRONT SIDE
      -0.5f * x, -0.5f * y, 0.5f * z, color.x, color.y, color.z,  // Lower left corner

      -0.5f * x, 0.5f * y, 0.5f * z, color.x, color.y, color.z,  // Upper left corner

      0.5f * x, 0.5f * y, 0.5f * z, color.x, color.y, color.z,  // Upper right corner

      0.5f * x, -0.5f * y, 0.5f * z, color.x, color.y, color.z,  // Lower right corner

      // BACK SIDE
      -0.5f * x, -0.5f * y, -0.5f * z, color.x, color.y, color.z,  // Lower left corner

      -0.5f * x, 0.5f * y, -0.5f * z, color.x, color.y, color.z,  // Upper left corner

      0.5f * x, 0.5f * y, -0.5f * z, color.x, color.y, color.z,  // Upper right corner

      0.5f * x, -0.5f * y, -0.5f * z, color.x, color.y, color.z  // Lower right corner
  };

  std::vector<GLuint> indices{
      // each three indices creates triangle,
      // each side of a ComplexCube is made of four recangles
      0, 1, 2, 0, 3, 2,
      4, 5, 6, 4, 7, 6,
      0, 1, 5, 0, 4, 5,
      3, 2, 6, 3, 7, 6,
      0, 3, 7, 0, 4, 7,
      1, 2, 6, 1, 5, 6
  };

  std::vector<GLuint> data_format{3, 3};
  return std::make_unique<VertexData>(std::move(vertices), std::move(indices), std::move(data_format));
}


std::unique_ptr<VertexData> BasicFigureFactory::MakeShadedCuboid(
    const glm::vec3 &dimensions,
    const glm::vec3 &color,
    const glm::vec2 &shading_level) const {

  GLfloat x(dimensions.x), y(dimensions.y), z(dimensions.z);
  GLfloat sh1(shading_level.x), sh2(shading_level.y);
  std::vector<GLfloat> vertices{
      // FRONT SIDE
      -0.5f * x, -0.5f * y, 0.5f * z, color.x, color.y, color.z,  // Lower left corner

      -0.5f * x, 0.5f * y, 0.5f * z, color.x, color.y, color.z,  // Upper left corner

      0.5f * x, 0.5f * y, 0.5f * z, color.x, color.y, color.z,  // Upper right corner

      0.5f * x, -0.5f * y, 0.5f * z, color.x, color.y, color.z,  // Lower right corner


      -0.5f * x, -0.5f * y, 0.5f * z, color.x * sh1, color.y* sh1, color.z* sh1,  // Lower left corner

      -0.5f * x, 0.5f * y, 0.5f * z, color.x* sh1, color.y* sh1, color.z* sh1,  // Upper left corner

      0.5f * x, 0.5f * y, 0.5f * z, color.x* sh1, color.y* sh1, color.z* sh1,  // Upper right corner

      0.5f * x, -0.5f * y, 0.5f * z, color.x* sh1, color.y* sh1, color.z* sh1,  // Lower right corner

      // BACK SIDE
      -0.5f * x, -0.5f * y, -0.5f * z, color.x* sh2, color.y* sh2, color.z* sh2,  // Lower left corner

      -0.5f * x, 0.5f * y, -0.5f * z, color.x* sh2, color.y* sh2, color.z* sh2,  // Upper left corner

      0.5f * x, 0.5f * y, -0.5f * z, color.x* sh2, color.y* sh2, color.z* sh2,  // Upper right corner

      0.5f * x, -0.5f * y, -0.5f * z, color.x* sh2, color.y* sh2, color.z* sh2,  // Lower right corner
  };

  std::vector<GLuint> indices{
      // each three indices creates triangle,
      // each side of a ComplexCube is made of four recangles
      0, 1, 2, 0, 3, 2,
      8, 9, 10, 8, 11, 10,
      4, 5, 9, 4, 8, 9,
      7, 6, 10, 7, 11, 10,
      4, 7, 11, 4, 8, 11,
      5, 6, 10, 5, 9, 10};

  std::vector<GLuint> data_format{3, 3};
  return std::make_unique<VertexData>(std::move(vertices), std::move(indices), std::move(data_format));
}

std::unique_ptr<VertexData> BasicFigureFactory::MakeDetailedCuboid(
    const glm::vec3 &dimensions, const glm::vec3 &vertex_color,
    const glm::vec3 &inner_color) const {

    GLfloat x(dimensions.x), y(dimensions.y), z(dimensions.z);

    std::vector<GLfloat> vertices {
    //EACH TWO ROWS REPRESENT ONE VERTEX
        // FRONT SIDE
        -0.5f * x, -0.5f * y, 0.5f * z, vertex_color.x, vertex_color.y, vertex_color.z,  // Lower left corner

        -0.5f * x, 0.5f * y, 0.5f * z, vertex_color.x, vertex_color.y, vertex_color.z,  // Upper left corner

        0.5f * x, 0.5f * y, 0.5f * z, vertex_color.x, vertex_color.y, vertex_color.z,  // Upper right corner

        0.5f * x, -0.5f * y, 0.5f * z, vertex_color.x, vertex_color.y, vertex_color.z,  // Lower right corner

        // BACK SIDE
        -0.5f * x, -0.5f * y, -0.5f * z, vertex_color.x, vertex_color.y, vertex_color.z,  // Lower left corner

        -0.5f * x, 0.5f * y, -0.5f * z, vertex_color.x, vertex_color.y, vertex_color.z,  // Upper left corner

        0.5f * x, 0.5f * y, -0.5f * z, vertex_color.x, vertex_color.y, vertex_color.z,  // Upper right corner

        0.5f * x, -0.5f * y, -0.5f * z, vertex_color.x, vertex_color.y, vertex_color.z,  // Lower right corner

        // INNER POINTS FOR EACH SIDE
        0.0f * x, 0.0f * y, 0.3f * z, inner_color.x, inner_color.y, inner_color.z,  // Dark inner point 1

        -0.3f * x, 0.0f * y, 0.0f * z, inner_color.x, inner_color.y, inner_color.z,  // Dark inner point 2

        0.0f * x, 0.0f * y, -0.3f * z, inner_color.x, inner_color.y, inner_color.z,  // Dark inner point 3

        0.3f * x, 0.0f * y, 0.0f * z, inner_color.x, inner_color.y, inner_color.z,  // Dark inner point 4

        0.0f * x, 0.3f * y, 0.0f * z, inner_color.x, inner_color.y, inner_color.z,  // Dark inner point 5

        0.0f * x, -0.3f * y, 0.0f * z, inner_color.x, inner_color.y, inner_color.z  // Dark inner point 6
    };

    std::vector<GLuint> indices{
        // each three indices creates triangle,
        // each side of a ComplexCube is made of four recangles
        0, 1, 8,  1, 2, 8,  2, 3, 8,  3, 0, 8,

        0, 1, 9,  1, 5, 9,  5, 4, 9,  4, 0, 9,

        5, 6, 10, 6, 7, 10, 7, 4, 10, 4, 5, 10,

        2, 6, 11, 6, 7, 11, 7, 3, 11, 3, 2, 11,

        1, 5, 12, 5, 6, 12, 6, 2, 12, 2, 1, 12,

        0, 4, 13, 4, 7, 13, 7, 3, 13, 3, 0, 13
    };

  std::vector<GLuint> data_format{3, 3};
  return std::make_unique<VertexData>(std::move(vertices), std::move(indices), std::move(data_format));}

std::unique_ptr<VertexData> BasicFigureFactory::MakeMazeFigure(
    const std::vector<glm::vec3> &walls_coordinates,
    std::unique_ptr<VertexData> wall_pattern) const {

    GLuint vertex_size = 6;
    GLuint wall_vertices_size = wall_pattern->vertices.size();
    GLuint wall_indices_size = wall_pattern->indices.size();
    GLuint number_of_vertices = wall_vertices_size / vertex_size;
    GLuint number_of_walls = walls_coordinates.size();
    std::vector<GLfloat> vertices(wall_vertices_size * walls_coordinates.size());
    std::vector<GLuint> indices(wall_indices_size * walls_coordinates.size());

    for (GLuint wall = 0; wall < number_of_walls; ++wall) {
      GLuint v_offset = wall * wall_vertices_size;
      GLuint i_offset = wall * wall_indices_size;
      GLuint index_offset = wall * number_of_vertices;
      for (size_t vert = 0; vert < wall_vertices_size; vert += vertex_size) {
        vertices[vert + v_offset] = wall_pattern->vertices[vert] + walls_coordinates[wall].x;
        vertices[vert + v_offset + 1] = wall_pattern->vertices[vert + 1] + walls_coordinates[wall].y;
        vertices[vert + v_offset + 2] = wall_pattern->vertices[vert + 2] + walls_coordinates[wall].z;
        vertices[vert + v_offset + 3] = wall_pattern->vertices[vert + 3];
        vertices[vert + v_offset + 4] = wall_pattern->vertices[vert + 4];
        vertices[vert + v_offset + 5] = wall_pattern->vertices[vert + 5];
      }
      for (size_t index = 0; index < wall_indices_size; ++index)
        indices[index + i_offset] = wall_pattern->indices[index] + index_offset;
    }
    std::vector<GLuint> data_format{3, 3};
    return std::make_unique<VertexData>(std::move(vertices), std::move(indices), std::move(data_format));
}

} //namespace graphics

