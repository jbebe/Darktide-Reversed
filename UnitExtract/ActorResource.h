#pragma once

#include "Vector.h"
#include "Array.h"
#include "Matrix4x4.h"
#include "IdString.h"

namespace stingray {
	struct __declspec(align(8)) ActorResource
	{
		struct __declspec(align(8)) Shape
		{
			int type;
			// $654173977C75DA1EEF8D91EF665378F0 ___u1; ???
			stingray::IdString32 material;
			stingray::IdString32 shape_template;
			stingray::Matrix4x4 local_tm;
			stingray::Array<char> shape_data;
			stingray::IdString32 shape_node;
		};

		IdString32 _name;
		IdString32 _actor_template;
		IdString32 _node;
		float _mass;
		Vector<stingray::ActorResource::Shape> _shapes;
		unsigned int _on_start_touch;
		unsigned int _on_stay_touching;
		unsigned int _on_end_touch;
		unsigned int _on_trigger_enter;
		unsigned int _on_trigger_leave;
		unsigned int _on_trigger_stay;
		bool _enabled;
	};
}