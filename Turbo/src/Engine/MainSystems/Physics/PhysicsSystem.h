#pragma once
#include <memory>

#include "Engine/CoreSystems/Math/Vector/Vector2D.h"
#include "Engine/MainSystems/Renderer/Renderer2D/Renderer2D.h"
#include "Engine/MainSystems/SceneGraph/GameObject/GameObject.h"
#include "Engine/MainSystems/SceneGraph/GameObject/Properties/Position.h"
#include "Engine/MainSystems/SceneGraph/GameObject/Properties/Sprite.h"

namespace Turbo
{
	class PhysicsSystem
	{

	public:
		// Collision Checks

		static std::shared_ptr<GameObject> checkIfObjectClicked(float clickX, float clickY, const std::vector<std::shared_ptr<GameObject>>& hierarchy)
		{
			for(int i = 0; i <= 0; i++)
			{
				std::shared_ptr<Position> position = std::dynamic_pointer_cast<Position>(hierarchy[i]->getPropertyByName(POSITION));

				Vector4D vec{position->pos.x, position->pos.y, position->pos.z, 1.0f};

				Vector3D scaled_pos = -Renderer2D::camera_position;
				scaled_pos.scale(Time::delta_time);
				//scaled_pos.scale(5);

				Matrix4 mat = Matrix4::identity;
				mat.translate(scaled_pos);

				Vector4D clipSpacePos = mat * vec;

				//std::cout << clipSpacePos.x << ' ' << clipSpacePos.y << '\n';

				//Vector2D windowSpacePos = { ((clipSpacePos.x + 1.0f) * 0.5f) * 1300, ((clipSpacePos.y + 1.0f) * 0.5f) * 932 };
				Vector2D windowSpacePos = { (650 * clipSpacePos.x) + 910, (466 * clipSpacePos.y) + 466};

				std::shared_ptr<Sprite> sprite = std::dynamic_pointer_cast<Sprite>(hierarchy[i]->getPropertyByName(SPRITE));

				//std::cout << windowSpacePos.x << ' ' << windowSpacePos.y << '\n';

				float left = windowSpacePos.x - (static_cast<float>(sprite->texture->getWidth()) / 2.0f);
				float right = windowSpacePos.x + (static_cast<float>(sprite->texture->getWidth()) / 2.0f);
				float bottom = windowSpacePos.y + (static_cast<float>(sprite->texture->getHeight()) / 2.0f);
				float top = windowSpacePos.y - (static_cast<float>(sprite->texture->getHeight()) / 2.0f);

				//std::cout << bottom << ' ' << top << ' ' << '\n';

				if(clickX >= left && clickX <= right && clickY >= top && clickY <= bottom)
					std::cout << clickX << ' ' << clickY << '\n';
			}
			return nullptr;
		}

	};
}
