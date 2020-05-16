/// \file		Main.cpp
/// \date		15/05/2020
/// \project	Oxy Engine
/// \author		DOCtriX

#include <stdexcept>
#include <iostream>

#include "C_OxyEngine.hpp"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-stack-address"

int main(int argc, char** argv)
{
	OxyEngine::S_WindowCreateInfo window_create_info {};
	window_create_info.window_width = 1280;
	window_create_info.window_height = 720;
	window_create_info.p_window_title = "Oxy Engine";

	OxyEngine::S_RendererCreateInfo renderer_create_info {};
	renderer_create_info.e_renderer_type = OxyEngine::E_RendererType::OpenGL33;
	renderer_create_info.p_window_create_info = &window_create_info;

	OxyEngine::S_RenderingEngineCreateInfo rendering_engine_create_info {};
	rendering_engine_create_info.e_rendering_engine_type = OxyEngine::E_RenderingEngineType::Rasterization;
	rendering_engine_create_info.p_renderer_create_info = &renderer_create_info;

	OxyEngine::S_OxyEngineCreateInfo oxy_engine_create_info {};
	oxy_engine_create_info.p_rendering_engine_create_info = &rendering_engine_create_info;

	OxyEngine::C_OxyEngine oxy_engine;

	try {
		oxy_engine.Initialize(oxy_engine_create_info);
		oxy_engine.Run();
	}
	catch (std::runtime_error& error)
	{
		std::cerr << "Exception : " << error.what() << std::endl;
	}
	catch (std::bad_alloc& error)
	{
		std::cerr << "Exception : " << error.what() << std::endl;
	}

	return 0;
}

#pragma clang diagnostic pop