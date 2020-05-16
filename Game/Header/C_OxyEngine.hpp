/// \file		C_OxyEngine.hpp
/// \date		15/05/2020
/// \project	Oxy Engine
/// \author		DOCtriX

#ifndef OXY_ENGINE_C_OXY_ENGINE_HPP_
#define OXY_ENGINE_C_OXY_ENGINE_HPP_

#include "Rendering/I_RenderingEngine.hpp"

namespace OxyEngine
{
	struct S_OxyEngineCreateInfo {
		S_RenderingEngineCreateInfo* p_rendering_engine_create_info;
	};

	class C_OxyEngine
	{
	public:

		~C_OxyEngine();
		void Initialize(const S_OxyEngineCreateInfo& oxy_engine_create_info);
		void Release();
		void Run();

	private:

		bool m_initialized = false;
		I_RenderingEngine* mp_rendering_engine = nullptr;
	};
}

#endif // !OXY_ENGINE_C_OXY_ENGINE_HPP_