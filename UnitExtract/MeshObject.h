#pragma once

#include "IdString.h"
#include "Vector.h"
#include "Array.h"
#include "TaggedHeapAllocator.h"
#include "BoundingVolume.h"
#include "MeshGeometry.h"
#include "SceneGraph.h"
#include "RenderPackageStream.h"
#include "SkinData.h"
#include "RenderStateObject.h"
#include "Material.h"

namespace stingray {
	namespace renderable {
		struct BatchInfo
		{
			enum PrimitiveType
			{
				TRIANGLE_LIST = 0x0,
				LINE_LIST = 0x1,
			};

			enum FrontFace
			{
				COUNTER_CLOCK_WISE = 0x0,
				CLOCK_WISE = 0x1,
			};

			PrimitiveType primitive_type;
			unsigned int vertex_offset;
			unsigned int primitives;
			unsigned int index_offset;
			unsigned int vertices;
			unsigned int instances;
			FrontFace front_face;
		};

		struct MeshBatchInfo
		{
			BatchInfo batch_info;
			unsigned int material_idx;
			unsigned int bone_set;
		};
	}

	const struct MeshObject : RenderStateObject
	{
		Allocator* _allocator;
		unsigned int _flags;
		char _visibility_contexts;
		unsigned __int64 _shader_pass_flags;
		IdString32 _name;
		SceneGraphHandle _node;
		MeshGeometry* _geometry;
		Array<renderable::MeshBatchInfo>* _batch_infos;
		BoundingVolume _bounding_volume;
		SkinData* _skin;
		Array<Material*> _materials;
	};
}