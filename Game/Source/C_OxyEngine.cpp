/// \file		C_OxyEngine.cpp
/// \date		15/05/2020
/// \project	Oxy Engine
/// \author		DOCtriX

#include <iostream>
#include <stdexcept>

#include "C_OxyEngine.hpp"
#include "Rendering/Rasterization/C_RasterizationEngine.hpp"

namespace OxyEngine {
	C_OxyEngine::~C_OxyEngine()
	{
		Release(); // RAII
	}

	void C_OxyEngine::Initialize(const S_OxyEngineCreateInfo& oxy_engine_create_info)
	{
		if (m_initialized)
			Release();
		switch (oxy_engine_create_info.p_rendering_engine_create_info->e_rendering_engine_type)
		{
		case Rasterization: mp_rendering_engine = new C_RasterizationEngine(); break;
		case RayTracingCPU: throw std::runtime_error("CPU Ray tracing engine not implemented.");
		case RayTracingGPU: throw std::runtime_error("GPU Ray tracing engine not implemented.");
		}
		if (!mp_rendering_engine)
			throw std::bad_alloc();

		m_initialized = true;
		mp_rendering_engine->Initialize(*oxy_engine_create_info.p_rendering_engine_create_info);

		std::cout << "Oxy engine initialized." << std::endl;
	}

	void C_OxyEngine::Release()
	{
		if (m_initialized)
		{
			if (mp_rendering_engine)
			{
				mp_rendering_engine->Release();

				delete mp_rendering_engine;
				mp_rendering_engine = nullptr;
			}

			std::cout << "Oxy Engine released." << std::endl;
		}
	}

	void C_OxyEngine::Run()
	{
		if (!m_initialized)
			throw std::runtime_error("Oxy Engine not initialized.");

		GLFWwindow* p_window = mp_rendering_engine->GetRenderer()->GetWindow()->GetHandle();

		// Timers
		double lag = 0.0;
		double previous = glfwGetTime();
		double SECONDS_PER_UPDATE = 1.0 / 60.0;

		while (!glfwWindowShouldClose(p_window) &&
			glfwGetKey(p_window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
		{
			double current = glfwGetTime();
			double elapsed = current - previous;
			previous = current;

			lag += elapsed;
			glfwPollEvents();

			while (lag >= SECONDS_PER_UPDATE)
			{
				// Game logic
				lag -= SECONDS_PER_UPDATE;
			}

			// Rendering
			mp_rendering_engine->Render(static_cast<float>((float)lag / SECONDS_PER_UPDATE));
		}
	}
} // namespace