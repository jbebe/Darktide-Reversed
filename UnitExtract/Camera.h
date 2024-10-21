#pragma once

#include "IdString.h"
#include "Vector.h"
#include "Array.h"
#include "SceneGraph.h"
#include "DynamicData.h"
#include "RenderStateObject.h"

namespace stingray {
	struct CameraData
	{
		enum Mode
		{
			MONO = 0x0,
			STEREO = 0x1,
		};

		enum ProjectionType
		{
			ORTHOGRAPHIC_PROJECTION = 0x0,
			PERSPECTIVE_PROJECTION = 0x1,
		};

		float near_range;
		float far_range;
		Mode mode;
		ProjectionType type;
	};

	struct ProjectionData
	{
		enum ComputationType
		{
			FIELD_OF_VIEW = 0x0,
			FRUSTUM_DIMENSIONS = 0x1,
			FRUSTUM_HALF_ANGLES = 0x2,
		};

		float vertical_fov;
		float min_x;
		float max_x;
		float min_z;
		float max_z;
		float shear_x;
		float shear_y;
		ComputationType type;
	};

	struct Camera : RenderStateObject
	{
		TraceAllocator _allocator;
		SceneGraphHandle _node;
		CameraData _camera_data;
		ProjectionData _projection_data[2];
		IdString32 _name;
		DynamicData _dynamic_data;
	};
}