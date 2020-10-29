#include "GameRenderer.h"
#include "Offsets.h"
#include "Memory.h"

namespace Engine
{
	Camera* GameRenderer::GetCamera()
	{
		auto pEngine = *Memory::Ptr<void**>(this, OFFSET_GAMERENDERER_ENGINE);
		return *Memory::Ptr<Camera**>(pEngine, OFFSET_GAMERENDERER_ENGINE_CAMERA);
	}

	GameRenderer* GameRenderer::GetInstance()
	{
		PEB peb = proc.GetPeb();
		uint64_t base = peb.ImageBaseAddress;
		return *reinterpret_cast<GameRenderer**>(base, ADDRESS_GAMERENDERER);
	}
}