/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#include "Camera.h"
#include "Offsets.h"
#include "Memory.h"

namespace Engine
{
	Vector3 Camera::GetViewRight()
	{
		return proc.Read<Vector3>((uintptr_t)this + OFFSET_CAMERA_VIEWRIGHT);
	}

	Vector3 Camera::GetViewUp()
	{
		return proc.Read<Vector3>((uintptr_t)this + OFFSET_CAMERA_VIEWUP);
	}

	Vector3 Camera::GetViewForward()
	{
		return proc.Read<Vector3>((uintptr_t)this + OFFSET_CAMERA_VIEFORWARD);
	}

	Vector3 Camera::GetViewTranslation()
	{
		return proc.Read<Vector3>((uintptr_t)this + OFFSET_CAMERA_VIEWTRANSLATION);
	}

	float Camera::GetViewFovX()
	{
		return proc.Read<float>((uintptr_t)this + OFFSET_CAMERA_VIEWFOVX);
	}

	float Camera::GetViewFovY()
	{
		return proc.Read<float>((uintptr_t)this + OFFSET_CAMERA_VIEWFOVY);
	}

	Vector3 Camera::WorldToScreen(Vector3& position)
	{
		Vector3 temp = position - GetViewTranslation();

		float x = temp.Dot(GetViewRight());
		float y = temp.Dot(GetViewUp());
		float z = temp.Dot(GetViewForward() * -1);

		return *(new Vector3(
			(2560 / 2) * (1 + x / GetViewFovX() / z),
			(1440 / 2) * (1 - y / GetViewFovY() / z),
			z));
	}
}