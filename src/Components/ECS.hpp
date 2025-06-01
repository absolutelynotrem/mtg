#pragma once

#include "../pch.hpp"
#include "./Component.hpp"
#include "./Health/Health.hpp"
#include "./Velocity/Velocity.hpp"

// unique ID for every entity
using EntityID = uint32_t;

class ECS {
// members
private:
	// tracker of every holder of a component type
	std::unordered_map<EntityID, Components::Health> m_HealthInstances = {};
	// std::unordered_map<EntityID, Components::Velocity> m_VelocityInstances = {};

// methods
public:
	ECS() = default;

	EmptyPossibleError AttachHealthComponent(EntityID id, Components::Health h);
	// EmptyPossibleError AttachVelocityComponent(EntityID id, Components::Velocity v);
	
	std::expected<Components::Health, GameError> GetHealthComponent(EntityID id);
	
// static
public:
	static EntityID AssignID();

private:
	static EntityID m_LastID;
};
