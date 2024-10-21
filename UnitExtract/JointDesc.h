#pragma once

#include "IdString.h"
#include "Vector3.h"

namespace stingray
{
	struct TimeStepPolicy {
		enum Mode
		{
			VARIABLE = 0x0,
			FIXED = 0x1,
		};
	};

	typedef TimeStepPolicy::Mode JointType;

	struct JointDesc
	{
		struct SphericalJoint
		{
		  float swing_limit;
		};

		IdString32 _name;
		IdString32 _actor_1;
		IdString32 _actor_2;
		Vector3 _normal_1;
		Vector3 _normal_2;
		Vector3 _axis_1;
		Vector3 _axis_2;
		Vector3 _global_axis;
		Vector3 _anchor_1;
		Vector3 _anchor_2;
		Vector3 _global_anchor;
		unsigned int _joint_flags;
		JointType _type;
		SphericalJoint _spherical;
	};
}