/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#pragma once

#include "Vector3.h"

namespace Engine
{
	class EntityInfo 
	{
		public:
			Vector3 GetPosition(WinProcess &proc);
			Vector3 GetHeadPosition(WinProcess &proc);
	};

	class Entity
	{
		public:
			EntityInfo* GetEntityInfo(WinProcess &proc);
	};
}
