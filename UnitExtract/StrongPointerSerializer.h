#pragma once

#include "Vector.h"
#include "InputArchive.h"

namespace stingray {
	struct Allocator;

	template<typename T>
	struct StrongPointerVectorSerializer
	{
		Vector<T*>* v;
		Allocator* a;

        static void __fastcall serialize(StrongPointerVectorSerializer<T>* $this, InputArchive* s) {}
    };
}