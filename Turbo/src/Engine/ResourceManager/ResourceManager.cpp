#include "ResourceManager.h"

#include <string>
#include <memory>
#include <unordered_map>

#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/Interfaces/IShaderProgram.h"
#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/Interfaces/ITexture.h"
#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/OpenGL/OpenGLApi.h"

namespace Turbo
{
	std::unordered_map<std::string, std::shared_ptr<ITexture>> ResourceManager::textures{};
	std::unordered_map<std::string, std::shared_ptr<IShaderProgram>> ResourceManager::shader_programs{};

	std::shared_ptr<ITexture> ResourceManager::getTexture(const std::string& texture_name)
	{
		for (const auto& entry : textures)
		{
			if (texture_name == entry.first)
				return entry.second;
		}

		// PROBLEM
		auto* api = new OpenGLApi();

		textures.insert(std::make_pair<>(
			texture_name,
			api->createTexture("C:\\dev\\Turbo\\Turbo\\assets\\tex.png")));

		std::cout << "texture";

		return textures[texture_name];
	}

	std::shared_ptr<IShaderProgram> ResourceManager::getShaderProgram(const std::string& shader_program_name)
	{
		for (const auto& entry : shader_programs)
		{
			if (shader_program_name == entry.first)
				return entry.second;
		}

		auto* api = new OpenGLApi();

		shader_programs.insert(std::make_pair<>(
			shader_program_name,
			api->createShaderProgram("C:\\dev\\Turbo\\Turbo\\src\\Engine\\Renderer\\Shaders\\shader.vertex", 
									"C:\\dev\\Turbo\\Turbo\\src\\Engine\\Renderer\\Shaders\\shader.fragment") 
			));

		return shader_programs[shader_program_name];
	}
}
