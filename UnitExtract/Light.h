#pragma once

#include "IdString.h"
#include "Vector.h"
#include "Array.h"
#include "RenderStateObject.h"
#include "Material.h"

namespace stingray {
	struct __declspec(align(8)) LightData
	{
		Vector3 color;
		float intensity;
		float parameters[7];
		unsigned int flags;
		unsigned int type;
		IdString64 material;
		unsigned __int16 ies_index;
	};

	struct Light : RenderStateObject
	{
		SceneGraphHandle _node;
		LightData _light_data;
		IdString32 _name;
		Material* _material;
	};
}