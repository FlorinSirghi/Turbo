#include "GameObject.h"

namespace Turbo
{
	std::shared_ptr<Property> GameObject::getPropertyByName(std::string_view name)
	{
		for (const auto& prop : properties)
			if (prop->name == name)
				return prop;
	}

	void GameObject::addProperty(std::shared_ptr<Property> property)
	{
		properties.emplace_back(property);
	}
}
