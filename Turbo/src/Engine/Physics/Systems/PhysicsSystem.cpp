#include "PhysicsSystem.h"

namespace Turbo
{
	void PhysicsSystem::update(std::vector<std::shared_ptr<GameObject>> hierarchy)
	{
		applyGravity(hierarchy);
		checkCollisions(hierarchy);
	}

	void PhysicsSystem::applyGravity(std::vector<std::shared_ptr<GameObject>> hierarchy)
	{
		for (int i = 0; i < hierarchy.size(); ++i)
		{
			std::shared_ptr<RigidBody> rb = std::dynamic_pointer_cast<RigidBody>(hierarchy[i]->getComponentByName(RIGIDBODY));

			if (rb != nullptr)
			{
				if (rb->inverseMass <= 0.0f)
					return;

				std::shared_ptr<Transform> transform = std::dynamic_pointer_cast<Transform>(hierarchy[i]->getComponentByName(TRANSFORM));

				Vector3D scaledVelocity = rb->velocity;
				scaledVelocity.scale(Time::delta_time);
				transform->position += scaledVelocity;

				std::cout << transform->position.y << '\n';

				if (rb->movable)
				{
					Vector3D acceleration_due_to_gravity = { 0.0f, -5.0f, 0.0f };
					rb->acceleration = acceleration_due_to_gravity;
				}

				Vector3D resulting_acceleration = rb->acceleration;

				resulting_acceleration.scale(Time::delta_time);
				rb->velocity += resulting_acceleration;

				rb->velocity.scale(powf(rb->damping, Time::delta_time));
			}
		}
	}

	// Collision Checks

	void PhysicsSystem::checkCollisions(std::vector<std::shared_ptr<GameObject>> hierarchy)
	{
		for (int i = 0; i < hierarchy.size() - 1; ++i)
			for (int j = i + 1; j < hierarchy.size(); ++j)
			{
				std::shared_ptr<BoxCollider> a = std::dynamic_pointer_cast<BoxCollider>(hierarchy[i]->getComponentByName(BOXCOLLIDER));
				std::shared_ptr<BoxCollider> b = std::dynamic_pointer_cast<BoxCollider>(hierarchy[j]->getComponentByName(BOXCOLLIDER));

				if (a != nullptr && b != nullptr)
				{
					if (CollisionSystem::TestAABBAABB(a, b))
						CollisionSystem::ResolveAABBAABB(hierarchy[i], hierarchy[j]);
				}
			}
	}

	std::shared_ptr<GameObject> PhysicsSystem::checkIfObjectClicked(float clickX, float clickY, const std::vector<std::shared_ptr<GameObject>>& hierarchy)
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

		for (int i = 0; i <= 0; i++)
		{
			//std::shared_ptr<Position> position = std::dynamic_pointer_cast<Position>(hierarchy[i]->getPropertyByName(POSITION));
			//std::shared_ptr<Sprite> sprite = std::dynamic_pointer_cast<Sprite>(hierarchy[i]->getPropertyByName(SPRITE));
			//float halfWidth = sprite->texture->getWidth() / 2.0f;
			//float halfHeight = sprite->texture->getHeight() / 2.0f;



		}
		return nullptr;
	}
}