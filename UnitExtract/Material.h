#pragma once

#include "IdString.h"
#include "Vector.h"
#include "Array.h"
#include "RenderStateObject.h"

namespace stingray {
	struct ShaderVariable
	{
		unsigned int klass;
		unsigned int elements;
		stingray::IdString32 name;
		unsigned int offset;
		unsigned int element_stride;
	};

	struct MaterialTemplate
	{
		struct TextureChannel
		{
			IdString32 channel;
			IdString64 name;
		};

		struct MaterialContext
		{
			IdString32 context;
			IdString32 material;
		};

		Array<MaterialTemplate::TextureChannel> textures;
		Array<MaterialTemplate::MaterialContext> material_contexts;
		IdString64 parent_material;
		// $CB1AFC09440D17A9B815E540D0F7F795 ___u3;
		Array<ShaderVariable> variable_reflection;
		Array<char> variable_data;
	};

	struct Material : RenderStateObject
	{
		enum ShaderInit
		{
			INIT_IMMEDIATE = 0x0,
			INIT_DEFER = 0x1,
		};

		struct ResourceChannel
		{
		  IdString32 channel;
		  RenderResource* resource;
		};

		MaterialTemplate* _material_template;
		Array<Material::ResourceChannel> _resources;
		IdString32 _shader;
		Material::ShaderInit _shader_init_mode;
		IdString64 _name;
		unsigned __int64 _shader_pass_flags;
	};
}