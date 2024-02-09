#ifndef ENGINE_GAMEPLAY_GAMEOBJECT_GAMEOBJECTMODEL_COMPONENT_H_
#define ENGINE_GAMEPLAY_GAMEOBJECT_GAMEOBJECTMODEL_COMPONENT_H_

#include <memory>
#include <string>

namespace Turbo
{
	constexpr int MAX_COMPONENTS = 100;
	constexpr std::string_view TRANSFORM = "TRANSFORM";
	constexpr std::string_view SPRITE = "SPRITE";
	constexpr std::string_view CAMERA = "CAMERA";
	constexpr std::string_view RIGIDBODY = "RIGIDBODY";
	constexpr std::string_view BOXCOLLIDER = "BOXCOLLIDER";

	inline int componentCounter = 0;

	template<class T>
	int getID()
	{
		static int componentID = componentCounter++;
		return componentID;
	}

	class ComponentPool
	{

	public:

		ComponentPool(size_t component_size)
		{
			this->component_size = component_size;
			data = new char[component_size * 100];
		}

		~ComponentPool()
		{
			delete[] data;
		}

		void* get(size_t index)
		{
			return data + index * component_size;
		}


	private:

		size_t component_size{ 0 };
		char* data{ nullptr };

	};
}

#endif // ENGINE_GAMEPLAY_GAMEOBJECT_GAMEOBJECTMODEL_COMPONENT_H_
