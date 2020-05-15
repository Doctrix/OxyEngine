/// \file		C_OpenGL33Renderer.cpp
/// \date		15/05/2020
/// \project	Oxy Engine
/// \author		DOCtriX

#include "Rendering/Renderer/OpenGL33/C_OpenGL33Renderer.hpp"

namespace OxyEngine
{
	void C_OpenGL33Renderer::~I_Renderer()
	{
		Release(); // RAII
	}

	void C_OpenGL33Renderer::Initialize(const S_RendererCreateInfo& renderer_create_info)
	{
		if (m_initialized)
			Release();

		mp_window = new
	}

	void C_OpenGL33Renderer::Release()
	{
	}
} // namespace