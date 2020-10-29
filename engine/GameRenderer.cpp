#include "GameRenderer.h"
#include "Offsets.h"
#include "Memory.h"

namespace Engine
{
	Camera* GameRenderer::GetCamera(WinProcess &proc)
	{
		uintptr_t pEngine = proc.Read<uintptr_t>((uintptr_t)this + OFFSET_PROFILEMANAGER_LOCAL_CAMERA);
		uintptr_t pCamera = proc.Read<uintptr_t>(pEngine);
		pCamera = proc.Read<uintptr_t>(pEngine + OFFSET_PROFILEMANAGER_ENGINE_CAMERA);
		pCamera = proc.Read<uintptr_t>(pEngine + OFFSET_PROFILEMANAGER_CAMERAMANAGER);
		
		return (Camera*)pCamera;
	}

	GameRenderer* GameRenderer::GetInstance(WinProcess &proc)
	{
		PEB peb = proc.GetPeb();
		uintptr_t base = peb.ImageBaseAddress;
		return *reinterpret_cast<GameRenderer**>(base, ADDRESS_GAMERENDERER);
	}
}