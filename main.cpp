#include "engine/Memory.h"
#include "engine/GameManager.h"

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
	auto pGameManager = Engine::GameManager::GetInstance(proc);
	
	std::cout << pGameManager->GetEntities(proc).GetSize();
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
					printf("\nLooping process %lx:\t%s\n", i.proc.pid, i.proc.name);

					PEB peb = i.GetPeb();
					short magic = i.Read<short>(peb.ImageBaseAddress);
					printf("\tBase:\t%lx\tMagic:\t%hx (valid: %hhx)\n", peb.ImageBaseAddress, magic, (char)(magic == IMAGE_DOS_SIGNATURE));

					read_loop(i);

					not_found = false;
					break;
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
