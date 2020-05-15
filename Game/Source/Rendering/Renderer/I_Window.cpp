/// \file		I_Window.cpp
/// \date		15/05/2020
/// \project	Oxy Engine
/// \author		DOCtriX

#include "Rendering/Renderer/I_Window.hpp"

namespace OxyEngine
{
	GLFWwindow* I_Window::GetHandle()
	{
		return mp_window;
	}
} //!namespace