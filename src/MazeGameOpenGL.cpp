#include "graphics/figure_data_factories/basic_figure_factory.hpp"
#include "graphics/figures/Figure.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtx/euler_angles.hpp"
#include <sstream>
#include <iomanip>

#include "glad/glad.h"
#include "GLFW/glfw3.h"



std::string Vec3ToStr(const glm::vec3 &vector) {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(3) << vector.x;
    stream << " ";
    stream << std::fixed << std::setprecision(3) << vector.y;
    stream << " ";
    stream << std::fixed << std::setprecision(3) << vector.z;
    stream << " ";

    return stream.str();
}   

const unsigned int width = 800;
const unsigned int height = 800;

int main()
{
	//BasicFigureFactory factory{};
  //auto shader = factory.MakeShader();
    glm::vec3 pose_ = {0.0, 0.0, 1};

    auto model = glm::rotate(glm::mat4(1.0f), pose_.x,
                                glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, pose_.y,
                                glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, pose_.z,
                                glm::vec3(0.0f, 0.0f, 1.0f));

    model = glm::eulerAngleXYZ(pose_.x, pose_.y, pose_.z);
    model = model * glm::eulerAngleXYZ(pose_.x, pose_.y, pose_.z);
    glm::vec3 pose_new = pose_;
    glm::extractEulerAngleXYZ(model, pose_new.x, pose_new.y, pose_new.z);

    auto view = glm::translate(glm::mat4(1.0f), glm::vec3(0.5f, 10.0f, 2.0f));
    model = view * model;
    view = model;

    std::cout << Vec3ToStr(glm::vec3(view[3])) << std::endl;

    
	std::cout << "Hello CMake. " << std::endl;
    std::cout << Vec3ToStr(pose_) << std::endl;
    std::cout << Vec3ToStr(pose_new) << std::endl;


    glfwInit();

    // Tell GLFW what version of OpenGL we are using
    // In this case we are using OpenGL 3.3

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Tell GLFW we are using the CORE profile
    // So that means we only have the modern functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFWwindow object of 800 by 800 pixels, naming it
    // "YoutubeOpenGL"
    GLFWwindow* window =
        glfwCreateWindow(width, height, "YoutubeOpenGL", NULL, NULL);
    // Error check if the window fails to create
    if (window == NULL) {
      std::cout << "Failed to create GLFW window" << std::endl;
      glfwTerminate();
      return -1;
    }
    // Introduce the window into the current context
    glfwMakeContextCurrent(window);

    // Load GLAD so it configures OpenGL
    gladLoadGL();
    // Specify the viewport of OpenGL in the Window
    // In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
    glViewport(0, 0, width, height);



    // Gets ID of uniform called "scale"

    /*
     * I'm doing this relative path thing in order to centralize all the
     * resources into one folder and not duplicate them between tutorial
     * folders. You can just copy paste the resources from the 'Resources'
     * folder and then give a relative path from this folder to whatever
     * resource you want to get to. Also note that this requires C++17, so go to
     * Project Properties, C/C++, Language, and select C++17
     */

    // Texture


    // Original code from the tutorial
    /*Texture brickTex("brick.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA,
    GL_UNSIGNED_BYTE); brickTex.texUnit(shaderProgram, "tex0", 0);*/

    // Variables that help the rotation of the pyramid
    float rotation = 0.0f;
    double prevTime = glfwGetTime();

    // Enables the Depth Buffer
    glEnable(GL_DEPTH_TEST);

    // Main while loop
    while (!glfwWindowShouldClose(window)) {
      // Specify the color of the background
      glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
      // Clean the back buffer and depth buffer
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      // Tell OpenGL which Shader Program we want to use

      // Simple timer
      double crntTime = glfwGetTime();
      if (crntTime - prevTime >= 1 / 60) {
        rotation += 0.5f;
        prevTime = crntTime;
      }
    
      glfwSwapBuffers(window);
      // Take care of all GLFW events
      glfwPollEvents();
    }


	return 0;
}
