#pragma once

#include "../Subsystems/GameSystem.h"

#include <vector>

namespace Turbo
{
	class GameObject
	{
	public:

		std::vector<GameSystem> interactions;

	};

}