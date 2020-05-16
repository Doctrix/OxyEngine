/// \file		C_OpenGL33Window.cpp
/// \date		15/05/2020
/// \project	Oxy Engine
/// \author		DOCtriX

#include <iostream>
#include <stdexcept>

#include "Rendering/Renderer/OpenGL33/C_OpenGL33Window.hpp"

namespace OxyEngine
{
	void ErrorCallback(int error, const char* description)
	{
		std::cerr << "Error : " << description << std::endl;
	}

	C_OpenGL33Window::~C_OpenGL33Window()
	{
		Release(); // RAII
	}

	void C_OpenGL33Window::Initialize(const S_WindowCreateInfo& window_create_info)
	{
		if (m_initialized)
			Release();

		if (!glfwInit())
		{
			throw std::runtime_error("Failed to initialize GLFW.");
		}

		m_initialized = true;
		glfwSetErrorCallback(ErrorCallback);
		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		mp_window = glfwCreateWindow(
			window_create_info.window_width,
			window_create_info.window_height,
			window_create_info.p_window_title,
			nullptr, nullptr);

		if (!mp_window)
		{
			glfwTerminate();
			throw std::runtime_error("Failed to create the window.");
		}

		glfwMakeContextCurrent(mp_window);
		glewExperimental = GL_TRUE;

		if (glewInit() != GLEW_OK)
		{
			glfwTerminate();
			throw std::runtime_error("Failed to initialize GLEW.");
		}

		glfwSetInputMode(mp_window, GLFW_STICKY_KEYS, GL_TRUE);
		std::cout << "OpenGL 3.3 window initialized." << std::endl;
	}

	void C_OpenGL33Window::Release()
	{
		if (m_initialized)
		{
			glfwTerminate();
			mp_window = nullptr;

			m_initialized = false;
			std::cout << "OpenGL 3.3 window released." << std::endl;
		}
	}
} // namespace