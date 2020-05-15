/// \file		C_OpenGL33Renderer.hpp
/// \date		15/05/2020
/// \project	Oxy Engine
/// \author		DOCtriX

#ifndef OXY_ENGINE_C_OPEN_GL_33_RENDERER_HPP_
#define OXY_ENGINE_C_OPEN_GL_33_RENDERER_HPP_

#include "Rendering/Renderer/I_Renderer.hpp"

namespace OxyEngine
{
	class C_OpenGL33Renderer : public I_Renderer
	{
	public:
		~I_Renderer() override;
		void Initialize(const S_RendererCreateInfo& renderer_create_info) final;
		void Release() final;
	};
} // namespace

#endif // !OXY_ENGINE_C_OPEN_GL_33_RENDERER_HPP_