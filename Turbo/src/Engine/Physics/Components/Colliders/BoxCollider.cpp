#include "BoxCollider.h"

#include "Engine/Gameplay/GameObject/GameObjectModel/GameObject.h"
#include "Engine/SceneGraph/Components/Transform.h"

namespace Turbo
{
	BoxCollider::BoxCollider() : Component()
	{
		name = BOXCOLLIDER;
	}
}
