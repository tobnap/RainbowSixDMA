/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#pragma once

#include "Array.h"
#include "Entity.h"

namespace Engine
{
	class GameManager
	{
		public:
			Array<Entity*> GetEntities(WinProcess &proc);

			static GameManager* GetInstance(WinProcess &proc);
	};
}
