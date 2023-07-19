#pragma once

#include "../GameObject/GameObject.h"
#include <memory>

namespace Turbo
{
	class Scene
	{
	public:

		void addObject(std::shared_ptr<GameObject>);
		std::shared_ptr<GameObject> getObjectByName(std::string_view);

		std::vector<std::shared_ptr<GameObject>> hierarchy;

	private:

	};
}

