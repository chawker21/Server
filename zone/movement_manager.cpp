#include "movement_manager.h"
#include "position.h"
#include "mob.h"
#include <stdio.h>

EQEmu::MovementManager::MovementManager()
{
}

EQEmu::MovementManager::~MovementManager()
{
}

void EQEmu::MovementManager::AddUnit(Mob *m)
{
	printf("Add unit %s\n", m->GetName());
}

void EQEmu::MovementManager::RemoveUnit(Mob *m)
{
	printf("Remove unit %s\n", m->GetName());
}

void EQEmu::MovementManager::IssueMoveToCommand(Mob * m, const glm::vec4 & pos)
{
}

void EQEmu::MovementManager::IssueRotateToCommand(Mob *m, float heading)
{
}

void EQEmu::MovementManager::ApplyForce(Mob * m, const glm::vec3 & dir, float force)
{
}

void EQEmu::MovementManager::Tick(double delta_time)
{
}
