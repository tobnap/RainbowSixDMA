/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#include "Entity.h"
#include "Offsets.h"
#include "Memory.h"

namespace Engine
{
	Vector3& Entity::GetPosition()
	{
		return *Memory::Ptr<Vector3*>(this, OFFSET_ENTITY_POSITION);
	}

	Vector3& Entity::GetHeadPosition()
	{
		return *Memory::Ptr<Vector3*>(this, OFFSET_ENTITY_HEADPOSITION);
	}
}