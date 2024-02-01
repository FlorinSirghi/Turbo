#ifndef ENGINE_CORE_IDS_ID_H
#define ENGINE_CORE_IDS_ID_H

#include <string>

namespace Turbo
{
	class ID
	{
	public :

		ID() : id(0){}

		int getID() const { return id; }
		void setID(int id) { this->id = id; }

    private:

        int id;

	};

	struct IDHash
	{
		std::size_t operator()(const ID& k) const
		{
			return std::hash<int>()(k.getID()) << 1;
		}
	};

	struct IDEqual
	{
		bool operator()(const ID& lhs, const ID& rhs) const
		{
			return lhs.getID() == rhs.getID();
		}
	};
}

#endif // ENGINE_CORE_IDS_ID_H
