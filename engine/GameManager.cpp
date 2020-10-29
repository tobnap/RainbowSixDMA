#include "GameManager.h"
#include "Offsets.h"

namespace Engine
{
	Entity* GameManager::GetEntityList(WinProcess &proc)
	{
		uintptr_t encrypted = proc.Read<uintptr_t>((uintptr_t)this + OFFSET_GAMEMANAGER_ENTITYLIST);
		return (Entity*)(((encrypted >> 0xC | encrypted << 0x34) + 0xFDF84BE05A7526D4) ^ 0xCA90740F16A90A3C);
	}

	uint16_t GameManager::GetEntityCount(WinProcess &proc)
	{
		uintptr_t encrypted = proc.Read<uintptr_t>((uintptr_t)this + OFFSET_GAMEMANAGER_ENTITYCOUNT);
		return (uint16_t)(((encrypted >> 0xC | encrypted << 0x34) + 0xFDF84BE05A7526D4) ^ 0xCA90740F16A90A3C);
	}

	GameManager* GameManager::GetInstance(WinProcess &proc)
	{
		PEB peb = proc.GetPeb();
		uintptr_t base = peb.ImageBaseAddress;
		return proc.Read<GameManager*>(base + ADDRESS_GAMEMANAGER);
	}
}
