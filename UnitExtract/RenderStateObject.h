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

namespace stingray {
	struct StateReflectionStream
	{
		TraceAllocator _create_destroy_allocator;
		TraceAllocator _rps_allocator;
		Allocator* _object_allocator;
		TaggedHeapAllocator* _tagged_heap_allocator;
		unsigned int _frame_marker;
		unsigned int _n_active_streams;
		Array<RenderPackageStream> _rps;
		RenderPackageStream _create_rps;
		RenderPackageStream _destroy_rps;
	};

	struct StateReflectionInterface
	{
		StateReflectionStream* srs;
	};

	struct RenderStateObject
	{
		unsigned int _marker;
		unsigned int render_handle;
		StateReflectionInterface* sri;
	};
}