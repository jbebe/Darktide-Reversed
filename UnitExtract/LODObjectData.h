#pragma once

#include "Vector.h"
#include "IdString.h"
#include "Vector3.h"
#include "BoundingVolume.h"
#include "SceneGraph.h"

namespace stingray {

	struct __declspec(align(8)) LODObjectData
	{
		struct Step
		{
		  float visible_height_range[2];
		  stingray::Vector<unsigned int> meshes;
		};

		Vector<LODObjectData::Step> steps;
		SceneGraphHandle node;
		BoundingVolume bounding_volume;
		unsigned int flags;
		IdString32 name;
	};
}