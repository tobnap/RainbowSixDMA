#pragma once

#include "Camera.h"

namespace Engine
{
	class GameRenderer
	{
		public:
			Camera* GetCamera();
			static GameRenderer* GetInstance();
	};
}