/// \file		I_Renderer.cpp
/// \date		15/05/2020
/// \project	Oxy Engine
/// \author		DOCtriX

#include "Rendering/Renderer/I_Renderer.hpp"

namespace OxyEngine
{
	I_Window* I_Renderer::GetWindow()
	{
		return mp_window;
	}
} // namespace