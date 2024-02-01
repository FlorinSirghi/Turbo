#ifndef PLATFORM_FILESYSTEM_H_
#define PLATFORM_FILESYSTEM_H_

#include <string>

namespace Turbo 
{
	class FileSystem
	{
	public:

		static std::string readFileAsString(const std::string& path);


	};

}

#endif // PLATFORM_FILESYSTEM_H_