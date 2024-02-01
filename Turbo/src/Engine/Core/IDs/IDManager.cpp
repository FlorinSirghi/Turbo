#include "IDManager.h"

namespace Turbo
{
    IDManager::IDManager()
    {
        next.setID(-1);
    }

    ID IDManager::generateID()
    {
        next.setID(next.getID() + 1);
        return next;
    }

    ID IDManager::getID(const GameObject& object)
    {
        if (hasID(object))
            return object.getID();
    }

    void IDManager::assignID(const GameObject& object, const ID& id)
    {
        object_ids[id] = object;
    }

    bool IDManager::hasID(const GameObject& object)
    {
        const ID id = object.getID();

        if (object_ids.contains(id))
            return true;

        return false;
    }

    void IDManager::freeID(const ID& id)
    {
        object_ids.erase(id);
    }

    int IDManager::getIDCount()
    {
        return object_ids.size();
    }

    void IDManager::ResetIDPool()
    {
        next.setID(-1);
        object_ids.clear();
    }
}
