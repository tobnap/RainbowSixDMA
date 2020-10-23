/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#pragma once

#include <cstdint>
#include <type_traits>
#include "../vmread/hlapi/hlapi.h"

namespace Engine
{
	class Memory
	{
		public:
			template <typename Type>
			static inline Type GetBaseAddress(WinProcess &proc)
			{
				PEB peb = proc.GetPeb();
				return peb.ImageBaseAddress;
			}

			template <typename Type, typename Base, typename Offset>
			static inline Type Ptr(WinProcess &proc, Base base, Offset offset)
			{
				return proc.Read<uint64_t>((uint64_t)base + offset);
			}
	};
}
