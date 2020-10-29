#include "Camera.h"
#include "Offsets.h"
#include "Memory.h"

namespace Engine
{
	Vector3 Camera::GetViewRight(WinProcess &proc)
	{
		return proc.Read<Vector3>((uintptr_t)this + OFFSET_CAMERA_VIEWRIGHT);
	}

	Vector3 Camera::GetViewUp(WinProcess &proc)
	{
		return proc.Read<Vector3>((uintptr_t)this + OFFSET_CAMERA_VIEWUP);
	}

	Vector3 Camera::GetViewForward(WinProcess &proc)
	{
		return proc.Read<Vector3>((uintptr_t)this + OFFSET_CAMERA_VIEFORWARD);
	}

	Vector3 Camera::GetViewTranslation(WinProcess &proc)
	{
		return proc.Read<Vector3>((uintptr_t)this + OFFSET_CAMERA_VIEWTRANSLATION);
	}

	float Camera::GetViewFovX(WinProcess &proc)
	{
		return proc.Read<float>((uintptr_t)this + OFFSET_CAMERA_VIEWFOVX);
	}

	float Camera::GetViewFovY(WinProcess &proc)
	{
		return proc.Read<float>((uintptr_t)this + OFFSET_CAMERA_VIEWFOVY);
	}

	Vector3 Camera::WorldToScreen(WinProcess &proc, Vector3& position)
	{
		Vector3 temp = position - GetViewTranslation(proc);

		float x = temp.Dot(GetViewRight(proc));
		float y = temp.Dot(GetViewUp(proc));
		float z = temp.Dot(GetViewForward(proc) * -1);

		return *(new Vector3(
			(2560 / 2) * (1 + x / GetViewFovX(proc) / z),
			(1440 / 2) * (1 - y / GetViewFovY(proc) / z),
			z));
	}
}