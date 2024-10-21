#pragma once

#include "IdString.h"
#include "Vector.h"
#include "Array.h"
#include "TaggedHeapAllocator.h"

namespace stingray {
	struct RenderPackageStream
	{
		struct MessageHeader
		{
			stingray::RenderPackageStream::MessageHeader* next;
			unsigned int type;
			unsigned int size;
			unsigned int data_offset;
		};

		TaggedHeapAllocator* _allocator;
		void* _buffer;
		RenderPackageStream::MessageHeader* _read_head;
		bool _link_messages;
		RenderPackageStream::MessageHeader* _prev_header;
		RenderPackageStream::MessageHeader* _first_linked_header;
	};
}