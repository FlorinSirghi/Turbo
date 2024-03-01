#pragma once

#include <memory>

#include "CollisionSystem.h"
#include "Engine/Core/Math/Matrix/Matrix4.h"
#include "Engine/Core/Math/Vector/Vector3D.h"
#include "Engine/Core/Math/Vector/Vector4D.h"
#include "Engine/Physics/Components/Interaction/RigidBody.h"
#include "Engine/Renderer/Components/Sprite.h"
#include "Engine/Renderer/Systems/Renderer2D/Renderer2D.h"
#include "Engine/SceneGraph/Scene/Scene.h"

namespace Turbo
{
	class PhysicsSystem
	{

	public:

		std::shared_ptr<CollisionSystem> collision_system;
		PhysicsSystem();


		void update(std::shared_ptr<Scene>& scene);
		void applyGravity(std::shared_ptr<Scene> scene);

		// Collision Checks
		void checkCollisions(std::shared_ptr<Scene> scene);

		static std::shared_ptr<GameObject> checkIfObjectClicked(float clickX, float clickY, const std::vector<std::shared_ptr<GameObject>>& hierarchy);

	};
}
