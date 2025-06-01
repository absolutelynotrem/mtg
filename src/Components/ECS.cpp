#include "./ECS.hpp"
#include <expected>

EntityID ECS::m_LastID = 0;

EntityID ECS::AssignID() {
	return ECS::m_LastID++;
}

/* EmptyPossibleError ECS::AttachComponent(EntityID id, std::unique_ptr<Component> component) {
	switch (component->GetName()) {
		case (ComponentType::Health):
			if (Components::Health* h = dynamic_cast<Components::Health*>(component.get())) {
				this->m_HealthInstances.emplace(id, std::move(component));
			} else {
				return std::unexpected(GameError::InvalidComponent);
			}

			break;
		default:
			return std::unexpected(GameError::InvalidComponent);
			break;
	}

	return NoError;
}*/

EmptyPossibleError ECS::AttachHealthComponent(EntityID id, Components::Health h) {
	auto it = this->m_HealthInstances.find(id);

	if (it != this->m_HealthInstances.end())
		return std::unexpected(GameError::ComponentAlreadyAttached);

	this->m_HealthInstances.emplace(id, h);
	return NoError;
}


std::expected<Components::Health, GameError> ECS::GetHealthComponent(EntityID id) {
	auto it = this->m_HealthInstances.find(id);

	if (it != this->m_HealthInstances.end()){
		return std::unexpected(GameError::ComponentNotAttached);
	}

	return it->second;
}
