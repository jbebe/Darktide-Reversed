#pragma once

#include "Vector.h"

namespace stingray {

	template <typename TFirst, typename TSecond, int X, int Y>
	struct Pair
	{
		TFirst first;
		TSecond second;
	};

	template<typename TKey, typename TValue, typename TComparator>
	struct __declspec(align(8)) SortMap
	{
		TComparator _less;
		Vector<Pair<TKey, TValue, 0, 0> > _data;
		bool _is_sorted;
	};
}