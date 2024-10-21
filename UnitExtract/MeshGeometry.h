#pragma once

#include "d3d11.h"

#include "Array.h"
#include "Vector.h"
#include "Vector3.h"
#include "IdString.h"
#include "BoundingVolume.h"

namespace stingray {
	template<typename T>
	struct D3DShaderProgram
	{
		Allocator* _allocator;
		//D3DRenderDevice* _device;
		Array<char>* _bytecode;
		ID3D11VertexShader* _shader;
		//D3DResourceBinder<ID3D11VertexShader>* _resource_binder;
	};

	struct __declspec(align(8)) D3DVertexDeclaration
	{
		struct VSInputLayout
		{
			D3DShaderProgram<ID3D11VertexShader>* vertex_shader;
			ID3D11InputLayout* input_layout;
		};

		Vector<D3DVertexDeclaration::VSInputLayout> input_layouts;
		Vector<D3D11_INPUT_ELEMENT_DESC> input_description;
		bool used;
	};

	struct VertexDeclaration : D3DVertexDeclaration {};

	struct RenderResource {};

	struct ImageFormat {
		enum Validity
		{
			STATIC = 0x0,
			UPDATABLE = 0x1,
		};
	};

	struct DynamicConfigValue {
		enum ValueType
		{
			NIL = 0x0,
			BOOL = 0x1,
			NUMBER = 0x2,
			STRING = 0x3,
			DATA = 0x4,
			ARRAY = 0x5,
			OBJECT = 0x6,
		};
	};

	namespace geometry {
		typedef ImageFormat::Validity Validity;
		
		typedef DynamicConfigValue::ValueType StreamType;
	}


	struct __declspec(align(8)) VertexStream: RenderResource
	{
		geometry::Validity validity;
		unsigned int version;
		unsigned int vertices;
		unsigned int stride;
		geometry::StreamType stream_type;
		// $40DE1B212166406E70DDEE745BBD442A ___u6; ???
		unsigned int additional_bind_flags;
	};

	struct IndexStream: RenderResource
	{
		struct Format {};

		geometry::Validity validity;
		unsigned int version;
		unsigned int indices;
		IndexStream::Format format;
		geometry::StreamType stream_type;
		// $846CA8B9DAD663EFE4C7BCB4E9B03F2C ___u6; ???
	};

	struct MeshTriangleFinder
	{
		unsigned int n_aabb_nodes;
		unsigned int nodes_offset;
		unsigned int primitives_offset;
	};

	struct MeshGeometry
	{
		struct BatchRange
		{
			unsigned int material_index;
			unsigned int start;
			unsigned int size;
			unsigned int bone_set;
		};

		VertexDeclaration vertex_declaration;
		VertexStream vertex_stream;
		IndexStream index_stream;
		Array<char> vertex_data;
		Array<char> triangle_indices;
		BoundingVolume bounding_volume;
		Array<IdString32> materials;
		Vector<BatchRange> batch_ranges;
		MeshTriangleFinder* triangle_finder;
	};
}

