#include <iostream>

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

void ErrorCallback(int error, const char* description)
{
	std::cerr << "Error : " << description << std::endl;
}

int main(int argc, char** argv)
{
	if (!glfwInit())
	{
		std::cerr << "Failed to initialize GLFW." << std::endl;
		return -1;
	}

	glfwSetErrorCallback(ErrorCallback);
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* p_window = glfwCreateWindow(1280, 720, "Game", nullptr, nullptr);
	if (!p_window)
	{
		glfwTerminate();
		std::cerr << "Failed to initialize the window." << std::endl;
		return -1;
	}

	glfwMakeContextCurrent(p_window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize GLEW." << std::endl;
		return -1;
	}

	glfwSetInputMode(p_window, GLFW_STICKY_KEYS, GL_TRUE);

	while (!glfwWindowShouldClose(p_window) &&
		glfwGetKey(p_window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		glfwSwapBuffers(p_window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}