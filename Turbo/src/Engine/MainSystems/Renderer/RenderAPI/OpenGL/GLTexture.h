#pragma once

#include "Engine/MainSystems/Renderer/RenderAPI/Interfaces/ITexture.h"

#include <string>

namespace Turbo
{
	class GLTexture : public ITexture
	{
	public:

		GLTexture(const std::string& path);

		void use() override;

	};
}
