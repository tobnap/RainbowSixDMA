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
		if (!Memory::IsValidPtr<Entity>(this))
			return *(new Vector3());

		return *Memory::Ptr<Vector3*>(this, OFFSET_ENTITY_POSITION);
	}

	Vector3& Entity::GetHeadPosition()
	{
		if (!Memory::IsValidPtr<Entity>(this))
			return *(new Vector3());

		return *Memory::Ptr<Vector3*>(this, OFFSET_ENTITY_HEADPOSITION);
	}
}