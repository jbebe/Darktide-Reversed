#pragma once

#include "Array.h"
#include "Vector.h"
#include "Matrix4x4.h"

namespace stingray  {
	const struct SkinData
	{
		Vector<Matrix4x4> inv_bind_matrices;
		Array<unsigned int> node_indices;
		Vector<stingray::Array<unsigned int> > matrix_index_sets;
	};
}