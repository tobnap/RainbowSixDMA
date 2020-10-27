/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#pragma once

#include "Vector3.h"
#include "Memory.h"

namespace Engine
{
	class Entity
	{
		public:
			uintptr_t GetEntityInfo(WinProcess &proc);
			Vector3 GetPosition(WinProcess &proc);
			Vector3 GetHeadPosition(WinProcess &proc);
    };
}
