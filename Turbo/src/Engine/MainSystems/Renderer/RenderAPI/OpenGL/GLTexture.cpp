#include "GLTexture.h"
#include "stb_image.h"
#include "glad/glad.h"

#include <iostream>

namespace Turbo
{
	GLTexture::GLTexture(const std::string& path)
	{
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		int width, height, channel_count;
		unsigned char* texture_data = stbi_load(path.c_str(), &width, &height, &channel_count, 0);

		if(texture_data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load texture : " << path << '\n';
		}

		stbi_image_free(texture_data);

	}

	void GLTexture::use()
	{
		glBindTexture(GL_TEXTURE_2D, id);
	}
}
