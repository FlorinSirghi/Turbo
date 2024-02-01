#ifndef ENGINE_CORE_IDS_IDMANAGER_H
#define ENGINE_CORE_IDS_IDMANAGER_H


#include <string>
#include <unordered_map>

#include "ID.h"
#include "Engine/Gameplay/GameObject/GameObjectModel/GameObject.h"

namespace Turbo
{
	class IDManager
	{
	private:

		ID next;

		std::unordered_map<ID, GameObject, IDHash, IDEqual> object_ids;

	public:

		IDManager();

		ID generateID();
		ID getID(const GameObject& object);
		void assignID(const GameObject& object, const ID& id);
		bool hasID(const GameObject& object);
		void freeID(const ID& id);
		int getIDCount();
		void ResetIDPool();
	};
}

#endif // ENGINE_CORE_IDS_IDMANAGER_H
