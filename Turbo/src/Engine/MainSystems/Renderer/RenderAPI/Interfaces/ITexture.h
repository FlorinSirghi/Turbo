#pragma once

namespace Turbo
{
	class ITexture
	{
	public:

		virtual void use() = 0;

		unsigned int getID() { return id; }
		unsigned int getWidth() { return width; }
		unsigned int getHeight() { return height; }

	protected:

		unsigned int id, width, height;
	};
}
