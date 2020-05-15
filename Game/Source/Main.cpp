/// \file		Main.cpp
/// \date		15/05/2020
/// \project	Oxy Engine
/// \author		DOCtriX

#include <stdexcept>
#include <iostream>
#include "Rendering/Renderer/OpenGL33/C_OpenGL33Window.hpp"

int main(int argc, char** argv)
{
	OxyEngine::C_OpenGL33Window opengl_window;
	OxyEngine::S_WindowCreateInfo window_create_info{};
	window_create_info.window_width = 1280;
	window_create_info.window_height = 720;
	window_create_info.p_window_title = "Oxy Engine";

	try
	{
		opengl_window.Initialize(window_create_info);
	}
	catch (std::runtime_error& error)
	{
		std::cerr << "Exception : " << error.what() << std::endl;
		return -1;
	}

	GLFWwindow* p_window = opengl_window.GetHandle();
	while (!glfwWindowShouldClose(p_window) &&
		glfwGetKey(p_window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		glfwSwapBuffers(p_window);
		glfwPollEvents();
	}

	return 0;
}