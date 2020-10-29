#include "engine/Memory.h"
#include "engine/GameManager.h"
#include "engine/GameRenderer.h"
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
	Engine::Camera* pCamera = Engine::GameRenderer::GetInstance(proc)->GetCamera(proc);
	
	Engine::Entity* pEntityList = pGameManager->GetEntityList(proc);

	while(true) {
		for (uint16_t i = 0; i < pGameManager->GetEntityCount(proc); i++)
		{
			Engine::Entity* pEntity = (Engine::Entity*)proc.Read<uintptr_t>((uintptr_t)pEntityList + (OFFSET_GAMEMANAGER_ENTITY_INDEX * i));
			Engine::EntityInfo* pEntityInfo = pEntity->GetEntityInfo(proc);
			Engine::Vector3 entityPos = pEntityInfo->GetPosition(proc);

			system((std::string("curl -d \"x=") + std::to_string(entityPos.x) + std::string("&y=") + std::to_string(entityPos.y) + std::string("&z=") + std::to_string(entityPos.z) + std::string("\" -X POST localhost/send-coords")).c_str());

			Engine::Vector3 screenPosition = pCamera->WorldToScreen(proc, pEntityInfo->GetPosition(proc));
			float distance = pCamera->GetViewTranslation(proc).Distance(pEntityInfo->GetPosition(proc));	
			
			if (screenPosition.z >= 1.0f)
			{
				printf("X: %f", screenPosition.x);
				printf("Distance: %f", distance);
			}
		}
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
			for (auto &proc : ctx.processList) {
				if (!strcasecmp("RainbowSix.exe", proc.proc.name)) {
					PEB peb = proc.GetPeb();
					short magic = proc.Read<short>(peb.ImageBaseAddress);
					auto g_base = peb.ImageBaseAddress;
					if (g_base != 0)
					{
						printf("\nR6 found %lx:\t%s\n", proc.proc.pid, proc.proc.name);
						printf("\tBase:\t%lx\tMagic:\t%hx (valid: %hhx)\n", peb.ImageBaseAddress, magic, (char)(magic == IMAGE_DOS_SIGNATURE));

						read_loop(proc);
						//std::thread read_thread(read_loop, std::ref(proc));
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
