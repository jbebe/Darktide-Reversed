#pragma once

namespace stingray {
	struct SceneGraph {};

	struct __declspec(align(8)) SceneGraphHandle
	{
		SceneGraph* _graph;
		int _index;
	};
}