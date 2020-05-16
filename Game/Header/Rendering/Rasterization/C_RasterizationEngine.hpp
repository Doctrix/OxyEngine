/// \file		C_RasterizationEngine.hpp
/// \date		15/05/2020
/// \project	Oxy Engine
/// \author		DOCtriX

#ifndef OXY_ENGINE_C_RASTERIZATION_ENGINE_HPP_
#define OXY_ENGINE_C_RASTERIZATION_ENGINE_HPP_

#include "Rendering/I_RenderingEngine.hpp"

namespace OxyEngine
{
	class C_RasterizationEngine : public I_RenderingEngine
	{
	public:

		~C_RasterizationEngine() override;

		void Initialize(const S_RenderingEngineCreateInfo& rendering_engine_create_info) final;
		void Release() final;
		void Render(float lag) final;
	};
} // !namespace

#endif // !OXY_ENGINE_C_RASTERIZATION_ENGINE_HPP_