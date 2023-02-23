#include "basic_figure_factory.hpp"

std::unique_ptr<Shader>BasicFigureFactory::MakeShader() const {

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
