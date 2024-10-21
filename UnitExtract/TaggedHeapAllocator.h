#pragma once

#include "IdString.h"
#include "Vector.h"
#include "Array.h"
#include "Allocator.h"
#include <atomic>

namespace stingray {
	struct CriticalSection {};
	struct TaggedHeap;

	struct TaggedHeapBlockAllocation
	{
		void* cpu_buffer;
		void* gpu_buffer;
		void* data;
	};

	struct TaggedHeapAllocator: Allocator
	{
		struct BlockAllocation
		{
		  unsigned __int64 offset;
		  void* original_cpu_buffer;
		  void* original_gpu_buffer;
		  void* data;
		  unsigned __int64 size;
		};


		Array<TaggedHeapAllocator::BlockAllocation> blocks;
		unsigned __int64 tag;
		std::atomic<unsigned __int64> total_bytes_allocated;
		TaggedHeap* tagged_heap;
	};

	struct __declspec(align(8)) TaggedHeap
	{
		struct AllocatedBlock
		{
			unsigned __int64 tag;
			unsigned __int64 offset;
			void* original_cpu_buffer;
			void* original_gpu_buffer;
			void* data;
			unsigned int free_list_index;
		};

		TaggedHeapBlockAllocation* (__cdecl* _block_allocation)(TaggedHeapBlockAllocation* result, unsigned __int64, unsigned int, void*);
		void(__cdecl* _block_deallocation)(TaggedHeapBlockAllocation, void*);
		void* _user_data;
		Allocator* _allocator;
		TraceAllocator* _block_allocator;
		Array<TaggedHeap::AllocatedBlock> _allocated_blocks;
		Vector<Array<unsigned int> > _free_blocks;
		Array<TaggedHeapBlockAllocation> _allocated_ptrs;
		unsigned int _n_threads;
		CriticalSection _cs;
		Array<TaggedHeapAllocator*> _tagged_heap_allocators;
		Array<TaggedHeapAllocator*> _free_tagged_heap_allocators;
		unsigned __int64 _tag_counter;
		Array<unsigned __int64> _free_tags;
		unsigned __int64 _current_memory_allocated;
		unsigned int _block_size;
	};
}