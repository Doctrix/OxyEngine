/// \file		I_RenderingEngine.hpp
/// \date		15/05/2020
/// \project	Oxy Engine
/// \author		DOCtriX

#ifndef OXY_ENGINE_I_RENDERING_ENGINE_HPP_
#define OXY_ENGINE_I_RENDERING_ENGINE_HPP_

#include "Rendering/Renderer/I_Renderer.hpp"

namespace OxyEngine
{
	enum E_RenderingEngineType
	{
		Rasterization,
		RayTracingCPU,
		RayTracingGPU
	};

	struct S_RenderingEngineCreateInfo
	{
		E_RenderingEngineType e_rendering_engine_type;
		S_RendererCreateInfo p_renderer_create_info;
	};

	class I_RenderingEngine
	{
	public:
		virtual ~I_RenderingEngine() = default;
		virtual void Initialize(const S_RenderingEngineCreateInfo& rendering_engine_create_info) = 0;
		virtual void Release() = 0;
		virtual void Render(float lag) = 0;

		I_Renderer* GetRenderer();

	protected:

		bool m_initialized = false;
		I_Renderer* mp_renderer = nullptr;
	};
} // !namespace

#endif // !OXY_ENGINE_I_RENDERING_ENGINE_HPP_