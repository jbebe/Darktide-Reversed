#pragma once

#include "Vector.h"

namespace stingray {
	struct TraceAllocator {};

	struct AllocateResult
	{
		void* p;
		unsigned __int64 size;
	};

	struct Allocator
	{
		const char* _name;
		Allocator* _next;
		Allocator* _prev;

		void* (__cdecl* __vecDelDtor)(Allocator*, unsigned int);
		AllocateResult* (__cdecl* allocate_with_result)(Allocator*, AllocateResult* result, unsigned __int64, unsigned int);
		unsigned __int64(__cdecl* deallocate)(Allocator*, void*);
		unsigned __int64(__cdecl* allocated_size)(Allocator*, void*);
		unsigned __int64(__cdecl* total_allocated)(Allocator*);
		void(__cdecl* backing_allocators)(Allocator*, Vector<Allocator*>*);
		bool(__cdecl* is_temp_allocator)(Allocator*);
	};
}