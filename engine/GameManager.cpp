/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#include "GameManager.h"
#include "Offsets.h"
#include "Memory.h"

namespace Engine
{
	Array<Entity*> GameManager::GetEntities()
	{
		return (Array<Entity*>*)proc.Read<uint64_t>(this + OFFSET_GAMEMANAGER_ENTITYLIST);
	}

	GameManager* GameManager::GetInstance()
	{
		PEB peb = proc.GetPeb();
		uint64_t base = peb.ImageBaseAddress;
		return proc.Read<uint64_t>(base + ADDRESS_GAMEMANAGER);
	}
}
