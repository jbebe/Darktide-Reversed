#pragma once

#include "IdString.h"
#include "Vector.h"
#include "Array.h"
#include "DynamicString.h"

namespace stingray {
	struct ScriptMethod
	{
		DynamicString klass;
		DynamicString f;
	};
}