/// \file		I_RenderingEngine.cpp
/// \date		15/05/2020
/// \project	Oxy Engine
/// \author		DOCtriX

#include "Rendering/I_RenderingEngine.hpp"

namespace OxyEngine
{
	I_Renderer* I_RenderingEngine::GetRenderer()
	{
		return mp_renderer;
	}
} // !namespace