#include "engine/Memory.h"
#include "engine/GameManager.h"
#include "engine/Offsets.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <random>
#include <thread>
#include <iostream>
#include <chrono>

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

void read_loop(WinProcess &proc) {
	Engine::GameManager* pGameManager = Engine::GameManager::GetInstance(proc);
	Engine::Entity* pEntityList = pGameManager->GetEntityList(proc);

	for (uint16_t i = 0; i < pGameManager->GetEntityCount(proc); i++)
	{
		Engine::Entity* pEntity = (Engine::Entity*)proc.Read<uintptr_t>((uintptr_t)pEntityList + (0x8 * i));
		Engine::EntityInfo* pEntityInfo = pEntity->GetEntityInfo(proc);
		Engine::Vector3 entityPos = pEntityInfo->GetPosition(proc);
		printf("%f\n", entityPos.x);
		//Engine::Vector3 screenPosition = pCamera->WorldToScreen(pEntity->GetPosition());
		//float distance = pCamera->GetViewTranslation().Distance(pEntity->GetPosition());
	}
}

__attribute__((constructor))
static void init() 
{
	pid_t pid = 0;
#if (LMODE() != MODE_EXTERNAL())
	pid = getpid();
#endif
	printf("Using Mode: %s\n", TOSTRING(LMODE));

	try {
		bool not_found = true;
		WinContext ctx(pid);

		printf("Searching for a process...\n");
		while (not_found) {
			for (auto &i : ctx.processList) {
				if (!strcasecmp("RainbowSix.exe", i.proc.name)) {
					PEB peb = i.GetPeb();
					short magic = i.Read<short>(peb.ImageBaseAddress);
					auto g_base = peb.ImageBaseAddress;
					if (g_base != 0)
					{
						printf("\nR6 found %lx:\t%s\n", i.proc.pid, i.proc.name);
						printf("\tBase:\t%lx\tMagic:\t%hx (valid: %hhx)\n", peb.ImageBaseAddress, magic, (char)(magic == IMAGE_DOS_SIGNATURE));

						read_loop(i);
						//std::thread read_thread(read_loop, std::ref(i));
						//read_thread.detach();

						not_found = false;
						break;
					}
				}
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		} 
	} catch (VMException& e) {
		printf("Initialization error: %d\n", e.value);
	}
}

int main() {
	return 0;
}
