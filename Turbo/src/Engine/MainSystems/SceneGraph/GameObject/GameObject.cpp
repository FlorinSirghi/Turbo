#include "GameObject.h"

namespace Turbo
{
	std::shared_ptr<Property> GameObject::getPropertyByName(std::string_view prop_name)
	{
		for (const auto& prop : properties)
			if (prop->name == prop_name)
				return prop;
	}

	void GameObject::addProperty(std::shared_ptr<Property> property)
	{
		properties.emplace_back(property);
	}
}
