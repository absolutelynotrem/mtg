#pragma once

#include "../pch.hpp"
#include "../Entity/Entity.hpp"
#include "Health/Health.hpp"
#include "Velocity/Velocity.hpp"
#include <expected>

/*
 * Storage<T>
 * -> List of T's
 * -> Give or remove the component T of any entity ID
 * -> Get the component instance of any ID (if any)
 * -> Acts as a list of any specific component instances
 *
 * Manager
 * -> HealthComponents is Storage with T = Health
 * -> VelocityComponents is Storage with T = Velocity
 * -> Easily attach and detach components to an ID
 * -> Manages all components
*/

// storage for every component type
template <typename T>
class ComponentStorage {
private:
// members
	std::unordered_map<EntityID, std::unique_ptr<T>> m_List = {};

// methods
public:
	// adds an id to the list
	EmptyPossibleError Add(EntityID id, T comp) {
		auto it = this->m_List.find(id);
		if (it != this->m_List.end())
			return std::unexpected(GameError::ComponentAlreadyAttached);

		this->m_List[id] = std::make_unique(std::move(comp));
		return NoError;
	}

	std::expected<T, GameError> Get(EntityID id) {
		auto it = this->m_List.find(id);

		if (it == this->m_List.end())
			return std::unexpected(GameError::ComponentNotAttached);

		return *it->second;
	}

	EmptyPossibleError Remove(EntityID id) {
		if (!this->Get(id).has_value()) {
			return std::unexpected(GameError::ComponentNotAttached);
		}

		this->m_List.erase(id);
		return NoError;
	}
};

class ComponentManager {
// members
private:
	ComponentStorage<Components::Health> m_HealthComponents;
	ComponentStorage<Components::Velocity> m_VelocityComponents;

// methods
public:
	template<typename T>
	ComponentStorage<T> GetStorage() {
		// basically an error
		static_assert(sizeof(T) != 0, "Storage not implemented for this type");
	}

	template<typename T>
	EmptyPossibleError Attach(EntityID id, T comp) {
		return std::unexpected(GameError::InvalidComponent);
	}
};
