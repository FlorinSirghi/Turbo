#include "ResourceManager.h"

#include "Engine/MainSystems/Renderer/RenderAPI/OpenGL/OpenGLApi.h"

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
			api->createShaderProgram("C:\\dev\\Turbo\\Turbo\\src\\Engine\\MainSystems\\Renderer\\Shaders\\shader.vertex", 
									"C:\\dev\\Turbo\\Turbo\\src\\Engine\\MainSystems\\Renderer\\Shaders\\shader.fragment") 
			));

		return shader_programs[shader_program_name];
	}
}
