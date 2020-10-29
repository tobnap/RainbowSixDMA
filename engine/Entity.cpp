#include "Entity.h"
#include "Offsets.h"

namespace Engine
{
	EntityInfo* Entity::GetEntityInfo(WinProcess &proc)
	{
		uintptr_t encrypted = proc.Read<uintptr_t>((uintptr_t)this + OFFSET_ENTITY_ENTITYINFO);
		//info ^= 0x59089C3C53641909;
		//info += 0x3E48F409BF6F5A50;
		//info ^= 0x155D2A1FBD952158;

		//return (EntityInfo*)info;
		return (EntityInfo*)(((encrypted ^ 0x59089C3C53641909) + 0x3E48F409BF6F5A50) ^ 0x155D2A1FBD952158);
	}

	Vector3 EntityInfo::GetPosition(WinProcess &proc)
	{
		return proc.Read<Vector3>((uintptr_t)this + OFFSET_ENTITY_POSITION);
	}

	Vector3 EntityInfo::GetHeadPosition(WinProcess &proc)
	{
		return proc.Read<Vector3>((uintptr_t)this + OFFSET_ENTITY_HEADPOSITION);
	}
}
