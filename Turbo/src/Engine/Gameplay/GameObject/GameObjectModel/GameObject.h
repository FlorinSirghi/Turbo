#ifndef ENGINE_GAMEPLAY_GAMEOBJECT_GAMEOBJECTMODEL_GAMEOBJECT_H_
#define ENGINE_GAMEPLAY_GAMEOBJECT_GAMEOBJECTMODEL_GAMEOBJECT_H_

#include <bitset>
#include <memory>
#include <vector>
#include <string>

#include "ComponentPool.h"
#include "Engine/Core/IDs/ID.h"


namespace Turbo
{
	class GameObject
	{
	public:

		GameObject(){
		}

		GameObject(ID id, const std::string& obj_name, int p_index = -1) : name(obj_name)
		{
			this->id = id;
			parent_index = p_index;
		}

		//virtual void onEvent(Event event){}

		std::string getName() { return name; }
		void setName(const std::string_view name) { this->name = name; }

		ID getID() const { return id; }
		void setID(const ID& id) { this->id = id; }

		int parent_index;
		std::vector<int> children_index;
		std::string name;
		std::bitset<MAX_COMPONENTS> componentMask;
		ID id;
	};

}

#endif // ENGINE_GAMEPLAY_GAMEOBJECT_GAMEOBJECTMODEL_GAMEOBJECT_H_