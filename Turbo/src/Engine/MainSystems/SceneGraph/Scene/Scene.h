#pragma once

#include "../GameObject/GameObject.h"
#include <memory>

namespace Turbo
{
	class Scene
	{
	public:

		std::vector<std::shared_ptr<GameObject>> hierarchy;

	};
}

