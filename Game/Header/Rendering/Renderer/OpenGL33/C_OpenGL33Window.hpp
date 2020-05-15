/// \file		C_OpenGL33Window.hpp
/// \date		15/05/2020
/// \project	Oxy Engine
/// \author		DOCtriX

#ifndef OXY_ENGINE_C_OPEN_GL_33_WINDOW_HPP_
#define OXY_ENGINE_C_OPEN_GL_33_WINDOW_HPP_

#include "Rendering/Renderer/I_Window.hpp"

namespace OxyEngine
{
	class C_OpenGL33Window : public I_Window
	{
	public:

		~C_OpenGL33Window() override;

		void Initialize(const S_WindowCreateInfo& window_create_info) final;
		void Release() final;
	};
} // namespace

#endif // !OXY_ENGINE_C_OPEN_GL_33_WINDOW_HPP_