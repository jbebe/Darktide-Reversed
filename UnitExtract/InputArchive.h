#pragma once

#include "IdString.h"
#include "Vector.h"
#include "Array.h"

namespace stingray {
	struct __declspec(align(8)) InputBuffer
	{
		__int64 _size;
		__int64 _buffer_start_pos;
		char* _buffer;
		char* _p;
		unsigned int _buffer_size;

		void* (__cdecl* __vecDelDtor)(stingray::InputBuffer*, unsigned int);
		void(__cdecl* set_position)(stingray::InputBuffer*, __int64);
		void(__cdecl* set_read_chunk)(stingray::InputBuffer*, unsigned int);
		void(__cdecl* flush)(stingray::InputBuffer*, unsigned int);
		bool(__cdecl* can_flush_without_stalling)(stingray::InputBuffer*);
	};

	template<typename T>
	struct SharedPtr
	{
		T* _p;
		Allocator* _allocator;
		unsigned int* _counter;
		void(__cdecl* _destruction_callback)(void*);
		void* _destruction_callback_userdata;
	};

	struct InputArchive
	{
		SharedPtr<InputBuffer> _buffer;
		__int64 _start;
		__int64 _size;
		__int64 _position;
		Array<void*> _pointers;

		static void read(InputArchive* $this, )
	};
}