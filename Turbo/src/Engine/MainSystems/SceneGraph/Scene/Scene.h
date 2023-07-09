#pragma once

#include "../GameObject/GameObject.h"
#include "../GameObject/UtilityObjects/OrthographicCamera.h"
#include <memory>

namespace Turbo
{
	class Scene
	{
	public:

		void addObject(std::shared_ptr<GameObject>);
		std::shared_ptr<GameObject> getObjectByName(std::string_view);

		std::shared_ptr<OrthographicCamera> getCamera();

		std::vector<std::shared_ptr<GameObject>> hierarchy;

	private:

	};
}

