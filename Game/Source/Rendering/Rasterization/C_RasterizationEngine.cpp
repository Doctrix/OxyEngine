/// \file		C_RasterizationEngine.cpp
/// \date		15/05/2020
/// \project	Oxy Engine
/// \author		DOCtriX

#include <iostream>
#include <stdexcept>

#include "Rendering/Rasterization/C_RasterizationEngine.hpp"
#include "Rendering/Renderer/OpenGL33/C_OpenGL33Renderer.hpp"

namespace OxyEngine
{
	C_RasterizationEngine::~C_RasterizationEngine()
	{
		Release(); // RAII
	}

	void C_RasterizationEngine::Initialize(const S_RenderingEngineCreateInfo& rendering_engine_create_info)
	{
		if (m_initialized)
			Release();

		switch (&rendering_engine_create_info.p_renderer_create_info->e_renderer_type)
		{
		case OpenGL33: mp_renderer = new C_OpenGL33Renderer(); break;
		case OpenGL45: throw std::runtime_error("OpenGL 4.5 renderer not implemented.");
		case Vulkan:throw std::runtime_error("Vulkan renderer not implemented.");
		}

		if (!mp_renderer)
			throw std::bad_alloc();

		m_initialized = true;
		mp_renderer->Initialize(rendering_engine_create_info.p_renderer_create_info);

		std::cout << "Rasterization engine initialized." << std::endl;
	}

	void C_RasterizationEngine::Release()
	{
		if (m_initialized)
		{
			if (mp_renderer)
			{
				mp_renderer->Release();
				delete mp_renderer;

				mp_renderer = nullptr;
			}
			m_initialized = false;
			std::cout << "Rasterization engine released." << std::endl;
		}
	}

	void C_RasterizationEngine::Render(float lag) {
		glfwSwapBuffers(mp_renderer->GetWindow()->GetHandle());
	}
} // !namespace