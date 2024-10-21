#pragma once

#include "Array.h"
#include "IdString.h"

namespace stingray {
	namespace terrain {
		struct Node
		{
			float height_min;
			float height_max;
			int children[4];
		};
	}

	struct TerrainData
	{
		struct Layer
		{
			enum Type
			{
				HMAP = 0x0,
				MATERIAL = 0x1,
			};

			struct DecorationUnit
			{
				IdString64 resource;
				IdString32 mesh;
				float density;
			};

			struct DecorationMaterial
			{
			  unsigned int n_units;
			  DecorationUnit units[4];
			};
			
			struct Context
			{
			  IdString32 name;
			  IdString32 materials[4];
			};

			struct SurfaceProperties
			{
				unsigned int num_contexts;
				Context contexts[8];
			};

			IdString64 map;
			unsigned int resolution;
			Type type;
			IdString32 materials[4];
			DecorationMaterial decoration_materials[4];
			SurfaceProperties surface_properties;
		};

		SceneGraphHandle node;
		BoundingVolume bounding_volume;
		unsigned int flags;
		IdString32 name;
		IdString32 base_material;
		Vector<terrain::Node> nodes;
		TerrainData::Layer layers[16];
		unsigned int n_layers;
		Array<char> height_data;
	};
}