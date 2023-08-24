#pragma once

#include <memory>
#include <unordered_map>

#include "Engine/MainSystems/Renderer/RenderAPI/Interfaces/IShaderProgram.h"
#include "Engine/MainSystems/Renderer/RenderAPI/Interfaces/ITexture.h"

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
