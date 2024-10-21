#pragma once

#include "IdString.h"
#include "Vector.h"
#include "Array.h"

namespace stingray {
	struct VehicleResource
	{
		bool _enabled;
		IdString32 _name;
		IdString32 _actor_name;
		IdString32 _vehicle_physics_model;
		IdString32 _tank_drive_model_name;
		/*VehicleResource::Chassis _chassis;
		VehicleResource::Engine _engine;
		VehicleResource::Differential _differential;
		VehicleResource::Gears _gears;
		VehicleResource::Clutch _clutch;
		VehicleResource::AckermannCorrection _ackermann_correction;
		VehicleResource::InputSmoothing _input_smoothing;
		VehicleResource::TireLoadFilter _tire_load_filter;
		Vector<VehicleResource::Wheel> _wheels;
		VehicleResource::SteerVsForwardSpeed _steer_vs_forward_speed;*/
	};
}