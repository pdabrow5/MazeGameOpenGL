#include "graphics/figure_data_factories/basic_figure_factory.hpp"
#include "graphics/figures/figure.hpp"
#include "graphics/figures/complex_figures/maze_figure.hpp"
#include "graphics/data_buffers/vertex_data_checkers/vertex_data_checker.hpp"

#include "glm/gtx/transform.hpp"
#include "glm/gtx/euler_angles.hpp"
#include <sstream>
#include <iomanip>

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <algorithm>


const unsigned int width = 800;
const unsigned int height = 800;

int main()
{
	//BasicFigureFactory factory{};
  //auto shader = factory.MakeShader();
    const auto p = graphics::MazeLayout::MazeCellType::path;
    const auto w = graphics::MazeLayout::MazeCellType::wall;
    const size_t maze_size = 1000;                                 // MAZE SIZE @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //std::vector<std::vector<graphics::MazeLayout::MazeCellType>> vec = {{w, p, p, w, w, p},
    //                                                       {p, p, p, w, w, p},
    //                                                       {w, p, p, w, w, p}};
    graphics::MazeLayout layout(maze_size, maze_size);
    auto x = layout.GetWallsCoordinates(5.0f);
    //for (auto row = layout.begin(); row != layout.end(); row++) {
    //  for (auto element = (*row).begin(); element != (*row).end(); element++)
    //    std::cout << *element << " ";
    //  std::cout << std::endl;
    //}

    //for (size_t row = 0; row < layout.size(); ++row) {
    //  for (size_t element = 0; element < layout[row].size(); ++element)
    //    std::cout << layout[row][element] << " ";
    //  std::cout << std::endl;
    //}


    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    GLFWwindow* window =
        glfwCreateWindow(width, height, "MazeGameOpenGL", NULL, NULL);
    // Error check if the window fails to create
    if (window == NULL) {
      std::cout << "Failed to create GLFW window" << std::endl;
      glfwTerminate();
      return -1;
    }
    // Introduce the window into the current context
    glfwMakeContextCurrent(window);

    //// Load GLAD so it configures OpenGL
    gladLoadGL();
    //// Specify the viewport of OpenGL in the Window
    //// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
    glViewport(0, 0, width, height);


    float rotation = 0.0f;

    //// Enables the Depth Buffer
    glEnable(GL_DEPTH_TEST);

    // Main while loop

    graphics::BasicFigureFactory factory;
    auto fig = factory.MakeFigure(factory.MakeDetailedCuboid(glm::vec3(0.90f, 0.90f, 1.5f),
                                          glm::vec3(0.9f, 0.9f, 0.9f),
                                          glm::vec3(0.1f, 0.1f, 0.1f)));

    auto fig2 = factory.MakeFigure(factory.MakeShadedCuboid(glm::vec3(1.5f, 1.5f, 3.0f),
                                         glm::vec3(0.0f, 0.9f, 0.9f),
                                         glm::vec2(0.7f, 0.1f)));

    auto rect = factory.MakeFigure(factory.MakeRectangle(glm::vec2(5.0f, 5.0f), glm::vec3(1.0f, 0.0f, 0.5f)));

    auto maze = factory.MakeFigure(factory.MakeMazeFigure(
        layout.GetWallsCoordinates(1.0f),
        factory.MakeShadedCuboid(glm::vec3(0.5f, 0.5f, 10.0f),
                                 glm::vec3(0.5f, 0.5f, 0.0f),
                                     glm::vec2(0.6f, 0.1f))));
    //auto fiddd = factory.MakeMazeFigure(
    //    layout.GetWallsCoordinates(1.0f),
    //    factory.MakeShadedCuboid(glm::vec3(0.5f, 0.5f, 30.0f),
    //                             glm::vec3(0.5f, 0.5f, 0.0f),
    //                             glm::vec2(0.1f, 0.8f)));
    //std::cout << "V:" << fiddd->vertices.size() << ", I: " << fiddd->indices.size() << std::endl;
    //graphics::MazeFigure maze(layout, *fig, 1.0f);

    fig->Move(glm::vec3{2.0f, 0.0f, -15.0f});
    fig->Rotate(glm::vec3(0.0f, 0.5f, 0.0f));

    fig2->Move(glm::vec3{-2.0f, 0.0f, -15.0f});
    fig2->Rotate(glm::vec3(0.0f, -0.5f, 0.0f));

    glm::vec3 maze_move(-0.0f, -0.0f, -1.4f);
    maze->Move(maze_move * (float)maze_size);

    rect->Move(glm::vec3{2.0f, 0.0f, -10.0f});
    double prevTime = glfwGetTime();
    double FPStime_c = prevTime;
    double FPStime_p = prevTime;
    double Tic = prevTime;
    double Tac = Tic;
    while (!glfwWindowShouldClose(window)) {
      double crntTime = glfwGetTime();
      FPStime_c = crntTime;
      if (crntTime - prevTime >= 1 / 60) {
        Tic = crntTime;
        Tac = crntTime;
        rotation += 0.5f;
        prevTime = crntTime;
        fig->Rotate(glm::vec3(0.03f, 0.0f, -0.0f));
        fig2->Rotate(glm::vec3(-0.03f, 0.0f, -0.0f));
        rect->Rotate(glm::vec3(-0.03f, 0.0f, -0.0f));
        maze->Rotate(glm::vec3(0.0f, 0.01f, 0.005f));
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        fig->Show();
        //fig2->Show();
        //rect->Show();
        maze->Show();
        glfwSwapBuffers(window);
        glfwPollEvents();
        Tac = glfwGetTime();
      }
      if ((FPStime_c - FPStime_p) > 1.0f) {
        std::cout << "FPS: " << (1 / (Tac - Tic)) << std::endl;
        FPStime_p = FPStime_c;
      }


      //fig3->Show();
    }
	return 0;
}
