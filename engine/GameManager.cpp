/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#include "GameManager.h"
#include "Offsets.h"
#include "Memory.h"

namespace Engine
{
	Array<Entity*> GameManager::GetEntities(WinProcess &proc)
	{
    		uint64_t entityList = proc.Read<uint64_t>((uint64_t)this + OFFSET_GAMEMANAGER_ENTITYLIST)
		uint64_t entityList1 = entityList >> 0xC;
    		uint64_t entityList2 = entityList << 0x34;
    		entityList = entityList1 | entityList2;
    		entityList += 0xFDF84BE05A7526D4;
    		entityList ^= 0xCA90740F16A90A3C;

		return (Array<Entity*>)entityList;
	}

	GameManager* GameManager::GetInstance(WinProcess &proc)
	{
		PEB peb = proc.GetPeb();
		uint64_t base = peb.ImageBaseAddress;
		return proc.Read<GameManager*>(base + ADDRESS_GAMEMANAGER);
	}
}
