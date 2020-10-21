/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#pragma once

#include <cstdint>
#include <type_traits>
#include "../vmread/hlapi/hlapi.h"

WinProcess proc;

namespace Engine
{
	class Memory
	{
		public:
			template <typename Type, typename Base, typename Offset>
			static inline Type Ptr(Base base, Offset offset)
			{
				return proc.Read<uint64_t>(base + offset);
			}
	};
}