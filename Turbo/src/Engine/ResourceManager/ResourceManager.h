#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <memory>
#include <string>
#include <unordered_map>

#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/Interfaces/IShaderProgram.h"
#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/Interfaces/ITexture.h"

namespace Turbo
{
	class ResourceManager
	{
	public:

		static std::shared_ptr<ITexture> getTexture(const std::string& texture_name);
		static std::shared_ptr<IShaderProgram> getShaderProgram(const std::string& shader_program_name);

	private:

		static std::unordered_map<std::string, std::shared_ptr<ITexture>> textures;
		static std::unordered_map<std::string, std::shared_ptr<IShaderProgram>> shader_programs;
	};
}

#endif // RESOURCEMANAGER_H_