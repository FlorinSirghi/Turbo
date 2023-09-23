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
			// opengl doesnt expect that I have something on top of the viewport so it expects that its top coordinate which is 900 px y axis
			// is 0 px in window coordinates
			// it does account for the x axis since it starts from the left also

			float yOffset = clickY - 100;

			float ndcX = ((clickX - (260.0f + 1300.0f / 2.0f)) * 2.0f) / 1300.0f;
			float ndcY = ((yOffset - (0.0f + 900.0f / 2.0f)) * 2.0f) / 900.0f;

			Vector4D ndcPos = { ndcX, ndcY, 0.0f, 1.0f };

			Vector3D scaled_pos = -Renderer2D::camera_position;
			scaled_pos.scale(Time::delta_time);
			//scaled_pos.scale(5);

			Matrix4 mat = Matrix4::identity;
			mat.translate(scaled_pos);

			/*Matrix4 m{ 1, 1, 1, -1, 1, 1, -1, 1, 1, -1, 1, 1, -1, 1, 1, 1 };
			m = m.getInverse();

			std::cout << m.e11 << ' ' << m.e12 << ' ' << m.e13 << ' ' << m.e14 << '\n';
			std::cout << m.e21 << ' ' << m.e22 << ' ' << m.e23 << ' ' << m.e24 << '\n';
			std::cout << m.e31 << ' ' << m.e32 << ' ' << m.e33 << ' ' << m.e34 << '\n';
			std::cout << m.e41 << ' ' << m.e42 << ' ' << m.e43 << ' ' << m.e44 << '\n';*/

			Vector4D worldPos = mat.getInverse() * ndcPos;

			//std::cout << worldPos.x << ' ' << worldPos.y << '\n';

			for(int i = 0; i <= 0; i++)
			{
				std::shared_ptr<Position> position = std::dynamic_pointer_cast<Position>(hierarchy[i]->getPropertyByName(POSITION));
				std::shared_ptr<Sprite> sprite = std::dynamic_pointer_cast<Sprite>(hierarchy[i]->getPropertyByName(SPRITE));
				//float halfWidth = sprite->texture->getWidth() / 2.0f;
				//float halfHeight = sprite->texture->getHeight() / 2.0f;



			}
			return nullptr;
		}

	};
}
