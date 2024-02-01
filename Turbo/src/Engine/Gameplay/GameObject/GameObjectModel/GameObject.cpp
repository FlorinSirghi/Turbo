#include "GameObject.h"

namespace Turbo
{
	std::shared_ptr<Component> GameObject::getComponentByName(std::string_view comp_name)
	{
		for (const auto& comp : components)
			if (comp->name == comp_name)
				return comp;
		return nullptr;
	}

	void GameObject::addComponent(std::shared_ptr<Component> component)
	{
		components.emplace_back(component);
	}
}

