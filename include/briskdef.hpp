#pragma once

#ifdef BRISK_REDEF_NULL
	#if (__cplusplus >= 201103L)
		#define NULL nullptr
	#else
		#define NULL 0
	#endif
#endif

namespace brisk
{
	using size_t = decltype(sizeof(int));
	using ptrdiff_t = signed long;
	using nullptr_t = decltype(nullptr);
}