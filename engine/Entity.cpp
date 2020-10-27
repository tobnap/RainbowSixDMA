/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#include "Entity.h"
#include "Offsets.h"
#include "Memory.h"

namespace Engine
{
	uintptr_t GetEntityInfo(WinProcess &proc)
	{
		uintptr_t info = proc.Read<uintptr_t>((uintptr_t)this + 0x50);
		info ^= 0x59089C3C53641909;
		info += 0x3E48F409BF6F5A50;
		info ^= 0x155D2A1FBD952158;

		return info;
	}

	Vector3 Entity::GetPosition(WinProcess &proc)
	{
		return proc.Read<Vector3>((uintptr_t)this + OFFSET_ENTITY_POSITION);
	}

	Vector3 Entity::GetHeadPosition(WinProcess &proc)
	{
		return proc.Read<Vector3>((uintptr_t)this + OFFSET_ENTITY_HEADPOSITION);
	}
}
