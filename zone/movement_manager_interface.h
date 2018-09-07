#pragma once

#include "position.h"

class Mob;

namespace EQEmu
{
	class IMovementManager
	{
	public:
		IMovementManager() { }
		virtual ~IMovementManager() { }

		virtual void AddUnit(Mob *m) = 0;
		virtual void RemoveUnit(Mob *m) = 0;
		virtual void IssueMoveToCommand(Mob *m, const glm::vec4 &pos) = 0;
		virtual void IssueRotateToCommand(Mob *m, float heading) = 0;
		virtual void ApplyForce(Mob *m, const glm::vec3 &dir, float force) = 0;
		virtual void Tick(double delta_time) = 0;
	};
}
