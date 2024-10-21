#pragma once

#include "Vector3.h"

namespace stingray {

	struct BoundingVolume
	{
		Vector3 min;
		Vector3 max;
		float radius;
	};

}