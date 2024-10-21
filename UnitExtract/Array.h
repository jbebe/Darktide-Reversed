#pragma once

namespace stingray {

	struct Allocator;

	template<typename T>
	struct Array
	{
		unsigned int _size;
		unsigned int _capacity;
		T* _data;
		Allocator* _allocator;
	};
}