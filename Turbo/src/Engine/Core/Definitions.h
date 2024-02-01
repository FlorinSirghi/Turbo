#ifndef ENGINE_CORE_DEFINITIONS_H_
#define ENGINE_CORE_DEFINITIONS_H_

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

#endif //  ENGINE_CORE_DEFINITIONS_H_