#ifndef GRAPHICS_WRAPPER_GLTEXTURE_H_
#define GRAPHICS_WRAPPER_GLTEXTURE_H_

#include <string>

#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/Interfaces/ITexture.h"

namespace Turbo
{
	class GLTexture : public ITexture
	{
	public:

		GLTexture(const std::string& path);

		void use() override;

	private:

		std::string path;
	};
}

#endif // GRAPHICS_WRAPPER_GLTEXTURE_H_
