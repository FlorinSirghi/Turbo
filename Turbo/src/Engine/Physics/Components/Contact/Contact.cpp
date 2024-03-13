#include "Contact.h"

#include <iostream>

namespace Turbo
{
	void Contact::resolve()
	{
		resolveVeloctiy();
	}

	float Contact::computeSeparatingVelocity() const
	{
		//std::cout << rigid_bodies[0]->velocity.x << ' ' << rigid_bodies[0]->velocity.y << ' ' << rigid_bodies[0]->velocity.z << '\n';

		Vector3D relative_velocity = rigid_bodies[0]->velocity;
		if (rigid_bodies[1])
		{
			relative_velocity -= rigid_bodies[1]->velocity;
		}
		return Vector3D::dotProduct(relative_velocity, contact_normal);
	}
	void Contact::resolveVeloctiy()
	{
		float separating_velocity = computeSeparatingVelocity();

		if(separating_velocity > 0)
		{
			return;
		}

		float new_separating_velocity = -separating_velocity * restitution_coefficient;
		float delta_veloctiy = new_separating_velocity - separating_velocity;

		float total_inverse_mass = rigid_bodies[0]->inverseMass;

		if (total_inverse_mass <= 0)
		{
			return;
		}

		float impulse = delta_veloctiy / total_inverse_mass;

		Vector3D impulse_per_mass = contact_normal.scaled(impulse);

		rigid_bodies[0]->velocity = (rigid_bodies[0]->velocity + impulse_per_mass.scaled(rigid_bodies[0]->inverseMass));

		if(rigid_bodies[1])
		{
			rigid_bodies[1]->velocity = (rigid_bodies[1]->velocity + impulse_per_mass.scaled(-rigid_bodies[1]->inverseMass));
		}
	}
}
