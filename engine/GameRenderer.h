#pragma once

#include "Camera.h"

namespace Engine
{
	class GameRenderer
	{
		public:
			Camera* GetCamera(WinProcess &proc);
			static GameRenderer* GetInstance(WinProcess &proc);
	};
}