#pragma once

#include "IdString.h"
#include "Vector.h"
#include "Array.h"

namespace stingray {
	struct DynamicString
	{
		Array<char> _buffer;
	};
}