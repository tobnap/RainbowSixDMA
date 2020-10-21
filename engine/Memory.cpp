#include "Memory.h"

/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <random>
#include <chrono>
*/

__attribute__((constructor))
static void init()
{
	FILE* out = stdout;
	pid_t pid = 0;
#if (LMODE() != MODE_EXTERNAL())
	pid = getpid();
#endif
	fprintf(out, "Using Mode: %s\n", TOSTRING(LMODE));

	vmread_dfile = out;

	try {
		WinContext ctx(pid);
		ctx.processList.Refresh();

		fprintf(out, "Process List:\nPID\tVIRT\t\t\tPHYS\t\tBASE\t\tNAME\n");
		for (auto& i : ctx.processList)
			fprintf(out, "%.4lx\t%.16lx\t%.9lx\t%.9lx\t%s\n", i.proc.pid, i.proc.process, i.proc.physProcess, i.proc.dirBase, i.proc.name);

		for (auto& i : ctx.processList) {
			if (!strcasecmp("RainbowSix.exe", i.proc.name)) {
				fprintf(out, "\nLooping process %lx:\t%s\n", i.proc.pid, i.proc.name);

				PEB peb = i.GetPeb();
				short magic = i.Read<short>(peb.ImageBaseAddress);
				fprintf(out, "\tBase:\t%lx\tMagic:\t%hx (valid: %hhx)\n", peb.ImageBaseAddress, magic, (char)(magic == IMAGE_DOS_SIGNATURE));
				auto g_Base = peb.ImageBaseAddress;
				if (g_Base != 0)
				{
					printf("\nR6 found %lx:\t%s\n", i.proc.pid, i.proc.name);
					printf("\tBase:\t%lx\tMagic:\t%hx (valid: %hhx)\n", peb.ImageBaseAddress, magic, (char)(magic == IMAGE_DOS_SIGNATURE));
					proc = std::ref(i);
					break;
				}
			}
		}
	} catch (VMException& e) {
		fprintf(out, "Initialization error: %d\n", e.value);
	}

	fclose(out);
}