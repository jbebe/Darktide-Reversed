#pragma once

#include "IdString.h"

namespace stingray {
	struct MoverDesc
	{
		IdString32 _name;
		float _height;
		float _radius;
		IdString32 _collision_filter;
		float _slope_limit;
		unsigned int _on_actor_hit;
		unsigned int _on_mover_hit;
	};
}