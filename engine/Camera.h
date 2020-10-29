#pragma once

#include "Vector3.h"
#include "Memory.h"

namespace Engine
{
	class Camera
	{
		public:
			Vector3 GetViewRight(WinProcess &proc);
			Vector3 GetViewUp(WinProcess &proc);
			Vector3 GetViewForward(WinProcess &proc);
			Vector3 GetViewTranslation(WinProcess &proc);
			float GetViewFovX(WinProcess &proc);
			float GetViewFovY(WinProcess &proc);

			Vector3 WorldToScreen(WinProcess &proc, Vector3 position);
	};
}
