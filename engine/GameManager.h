#pragma once

#include "Entity.h"
#include "Memory.h"

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
