#pragma once

#include "IdString.h"
#include "Vector.h"
#include "Array.h"

namespace stingray {
	struct __declspec(align(8)) MiniMemory
	{
		Array<char>* _data;
		unsigned int _freelist;
	};

	struct DynamicData
	{
		Array<char> _data;
		MiniMemory _allocator;
	};
}