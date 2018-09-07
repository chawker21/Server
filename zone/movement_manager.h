#pragma once

#include "movement_manager_interface.h"

namespace EQEmu
{
	class MovementManager : public IMovementManager
	{
	public:
		MovementManager();
		virtual ~MovementManager();

		virtual void AddUnit(Mob *m);
		virtual void RemoveUnit(Mob *m);
		virtual void IssueMoveToCommand(Mob *m, const glm::vec4 &pos);
		virtual void IssueRotateToCommand(Mob *m, float heading);
		virtual void ApplyForce(Mob *m, const glm::vec3 &dir, float force);
		virtual void Tick(double delta_time);
	};
}
