/// \file		I_Window.hpp
/// \date		15/05/2020
/// \project	Oxy Engine
/// \author		DOCtriX

#ifndef OXY_ENGINE_I_WINDOW_HPP_
#define OXY_ENGINE_I_WINDOW_HPP_

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

namespace OxyEngine
{
	struct S_WindowCreateInfo
	{
		int window_width;
		int window_height;
		const char* p_window_title;
	};

	class I_Window
	{
	public:

		virtual ~I_Window() = default;
		virtual void Initialize(const S_WindowCreateInfo& window_create_info) = 0;
		virtual void	Release() = 0;

		GLFWwindow* GetHandle();

	protected:

		bool	m_initialized = false;
		GLFWwindow* mp_window = nullptr;
	};
} // !namespace

#endif // !OXY_ENGINE_I_WINDOW_HPP_