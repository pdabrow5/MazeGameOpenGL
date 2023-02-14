// MazeGameOpenGL.cpp : Defines the entry point for the application.
//

#include "MazeGameOpenGL.h"
#include "graphics/figure_data_factories/basic_figure_factory.hpp"


int main()
{
	BasicFigureFactory factory{};
  auto shader = factory.MakeShader();
	foo::func();
	std::cout << "Hello CMake. " << std::endl;
	return 0;
}
