#include "GameRenderer.h"
#include "Offsets.h"

namespace Engine
{
	Camera* GameRenderer::GetCamera(WinProcess &proc)
	{
		uintptr_t pEngineLink = proc.Read<uintptr_t>((uintptr_t)this + OFFSET_GAMERENDERER_ENGINELINK);
		pEngineLink = proc.Read<uintptr_t>(pEngineLink);
		uintptr_t pEngine = proc.Read<uintptr_t>(pEngineLink + OFFSET_ENGINELINK_ENGINE);
		return (Camera*)proc.Read<uintptr_t>(pEngine + OFFSET_ENGINE_CAMERA);
	}

	GameRenderer* GameRenderer::GetInstance(WinProcess &proc)
	{
		PEB peb = proc.GetPeb();
		uintptr_t base = peb.ImageBaseAddress;
		return (GameRenderer*)proc.Read<uintptr_t>(base + ADDRESS_GAMERENDERER);
	}
}
