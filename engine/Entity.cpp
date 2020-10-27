/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#include "Entity.h"
#include "Offsets.h"
#include "Memory.h"

namespace Engine
{
	Vector3 Entity::GetPosition(WinProcess &proc)
	{
		return proc.Read<Vector3>((uintptr_t)this + OFFSET_ENTITY_POSITION);
	}

	Vector3 Entity::GetHeadPosition(WinProcess &proc)
	{
		return proc.Read<Vector3>((uintptr_t)this + OFFSET_ENTITY_HEADPOSITION);
	}
}
