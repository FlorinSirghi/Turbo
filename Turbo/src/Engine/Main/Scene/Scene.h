#pragma once

#include "../GameObject/GameObject.h"
#include <memory>

namespace Turbo
{
	class Scene
	{
	public:

		std::vector<std::unique_ptr<GameObject>> hierarchy;

	};
}

