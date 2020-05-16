/// \file		C_OpenGL33Renderer.cpp
/// \date		15/05/2020
/// \project	Oxy Engine
/// \author		DOCtriX

#include <iostream>
#include "Rendering/Renderer/OpenGL33/C_OpenGL33Renderer.hpp"

namespace OxyEngine
{
	C_OpenGL33Renderer::~C_OpenGL33Renderer()
	{
		Release(); // RAII
	}

	void C_OpenGL33Renderer::Initialize(const S_RendererCreateInfo& renderer_create_info)
	{
		if (m_initialized)
			Release();

		m_initialized = true;
		m_window.Initialize(renderer_create_info.p_window_create_info);
		mp_window = &m_window;

		std::cout << "OpenGL 3.3 renderer initialized." << std::endl;
	}

	void C_OpenGL33Renderer::Release()
	{
		if (m_initialized)
		{
			m_window.Release();
			mp_window = nullptr;
			m_initialized = false;
			std::cout << "OpenGL 3.3 renderer released." << std::endl;
		}
	}
} // namespace