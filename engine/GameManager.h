/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#pragma once

#include "Entity.h"

namespace Engine
{
	class GameManager
	{
		public:
			Entity* GetEntityList(WinProcess &proc);
			uint16_t GetEntityCount(WinProcess &proc);
			static GameManager* GetInstance(WinProcess &proc);
	};
}
