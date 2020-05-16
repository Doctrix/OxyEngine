/// \file		I_Renderer.hpp
/// \date		15/05/2020
/// \project	Oxy Engine
/// \author		DOCtriX

#ifndef OXY_ENGINE_I_RENDERER_HPP_
#define OXY_ENGINE_I_RENDERER_HPP_

#include "Rendering/Renderer/I_Window.hpp"

namespace OxyEngine
{
	enum E_RendererType
	{
		OpenGL33,
		OpenGL45,
		Vulkan
	};

	struct S_RendererCreateInfo
	{
		E_RendererType		e_renderer_type;
		S_WindowCreateInfo	p_window_create_info;
	};

	class I_Renderer
	{
	public:

		virtual		~I_Renderer() = default;
		virtual void Initialize(const S_RendererCreateInfo& renderer_create_info) = 0;
		virtual void Release() = 0;

		I_Window* GetWindow();

	protected:

		bool	m_initialized = false;
		I_Window* mp_window = nullptr;
	};
} // namespace

#endif // !OXY_ENGINE_I_RENDERER_HPP_