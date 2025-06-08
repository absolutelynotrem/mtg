#pragma once

#include "../pch.hpp"
#include "./Component.hpp"
#include "./Health/Health.hpp"
#include "./Velocity/Velocity.hpp"

class ECS {
// members
private:
	ComponentManager m_Manager;

// methods
public:
	ECS() = default;

	ComponentManager& Manager();

// static
public:
	static EntityID AssignID();

private:
	static EntityID m_LastID;
};
