#pragma once
#include <iostream>

#ifdef TURBO_WINDOWS
	#ifdef TURBO_EXPORT
		#define TURBO_API __declspec(dllexport)
	#else
		#define TURBO_API __declspec(dllimport)
	#endif
#else
	#error Turbo only supports Windows for now.
#endif
