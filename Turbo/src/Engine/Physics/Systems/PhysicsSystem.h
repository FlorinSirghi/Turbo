#pragma once

#include <memory>

#include "CollisionSystem.h"
#include "Engine/Core/Math/Matrix/Matrix4.h"
#include "Engine/Core/Math/Vector/Vector3D.h"
#include "Engine/Core/Math/Vector/Vector4D.h"
#include "Engine/Physics/Components/Interaction/RigidBody.h"
#include "Engine/Renderer/Components/Sprite.h"
#include "Engine/Renderer/Systems/Renderer2D/Renderer2D.h"

namespace Turbo
{
	class PhysicsSystem
	{

	public:

		void update(std::vector<std::shared_ptr<GameObject>> hierarchy);
		void applyGravity(std::vector<std::shared_ptr<GameObject>> hierarchy);

		// Collision Checks
		void checkCollisions(std::vector<std::shared_ptr<GameObject>> hierarchy);

		static std::shared_ptr<GameObject> checkIfObjectClicked(float clickX, float clickY, const std::vector<std::shared_ptr<GameObject>>& hierarchy);

	};
}
