#ifndef ENGINE_GAMEPLAY_GAMEOBJECT_GAMEOBJECTMODEL_GAMEOBJECT_H_
#define ENGINE_GAMEPLAY_GAMEOBJECT_GAMEOBJECTMODEL_GAMEOBJECT_H_

#include <memory>

#include <vector>

#include "Component.h"
#include "Engine/Gameplay/EventSystem/Event.h"
#include "Engine/Core/IDs/ID.h"
#include "Engine/Core/Definitions.h"


namespace Turbo
{
	class GameObject
	{
	public:

		GameObject(){
		}

		GameObject(ID id, const std::string& obj_name) : name(obj_name)
		{
			this->id = id;
		}

		// Specific for each game object

		virtual void onEvent(Event event){}
		virtual void update()
		{
			//for (const auto& comp : components)
				//comp->update();
		}

		// Same for all objects

		std::shared_ptr<Component> getComponentByName(std::string_view name);
		void addComponent(std::shared_ptr<Component> component);

		virtual ~GameObject() = default;

		// Setters & Getters

		std::string getName() { return name; }
		void setName(const std::string_view name) { this->name = name; }

		ID getID() const { return id; }
		void setID(const ID& id) { this->id = id; }

	protected:

		std::string name;
		std::vector<std::shared_ptr<Component>> components;
		ID id;
	};

}

#endif // ENGINE_GAMEPLAY_GAMEOBJECT_GAMEOBJECTMODEL_GAMEOBJECT_H_