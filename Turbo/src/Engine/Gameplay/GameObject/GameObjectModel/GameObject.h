#ifndef ENGINE_GAMEPLAY_GAMEOBJECT_GAMEOBJECTMODEL_GAMEOBJECT_H_
#define ENGINE_GAMEPLAY_GAMEOBJECT_GAMEOBJECTMODEL_GAMEOBJECT_H_

#include <bitset>
#include <memory>

#include "ComponentPool.h"
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

		virtual void onEvent(Event event){}

		std::string getName() { return name; }
		void setName(const std::string_view name) { this->name = name; }

		ID getID() const { return id; }
		void setID(const ID& id) { this->id = id; }

		std::string name;
		std::bitset<MAX_COMPONENTS> componentMask;
		ID id;
	};

}

#endif // ENGINE_GAMEPLAY_GAMEOBJECT_GAMEOBJECTMODEL_GAMEOBJECT_H_