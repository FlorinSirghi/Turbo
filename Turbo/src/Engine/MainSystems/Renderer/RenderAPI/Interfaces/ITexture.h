#pragma once

namespace Turbo
{
	class ITexture
	{
	public:

		virtual void use() = 0;

		unsigned int getID() { return id; }

	protected:

		unsigned int id;
	};
}
