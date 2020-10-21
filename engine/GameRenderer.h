/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

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