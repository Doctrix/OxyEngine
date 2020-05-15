/// \file		C_OpenGL33Renderer.hpp
/// \date		15/05/2020
/// \project	Oxy Engine
/// \author		DOCtriX

#ifndef OXY_ENGINE_C_OPEN_GL_33_RENDERER_HPP_
#define OXY_ENGINE_C_OPEN_GL_33_RENDERER_HPP_

#include "Rendering/Renderer/IRenderer.hpp"
#include "Rendering/Renderer/OpenGL33/C_OpenGL33Window.hpp"

namespace OxyEngine
{
	class C_OpenGL33Renderer : public I_Renderer
	{
	public:

		~I_Renderer() override;
		void Initialize(const S_RendererCreateInfo& renderer_create_info) final;
		void Release() final;

	private:
		C_OpenGL33Window m_window;
	};
} // namespace

#endif // !OXY_ENGINE_C_OPEN_GL_33_RENDERER_HPP_