#pragma once

#ifdef TURBO_EXPORT
#define TURBO_API __declspec(dllexport)
#else
#define TURBO_API __declspec(dllimport)
#endif
