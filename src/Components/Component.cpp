#include "./Component.hpp"

// storage getter specializations
template<>
ComponentStorage<Components::Health> ComponentManager::GetStorage<Components::Health>() {
	return this->m_HealthComponents;
}

template<>
ComponentStorage<Components::Velocity> ComponentManager::GetStorage<Components::Velocity>() {
	return this->m_VelocityComponents;
}

// attach specializations
template<>
EmptyPossibleError ComponentManager::Attach<Components::Health>(EntityID id, Components::Health comp) {	
	return this->m_HealthComponents.Add(id, comp);
}

template<>
EmptyPossibleError ComponentManager::Attach<Components::Velocity>(EntityID id, Components::Velocity comp) {
	return this->m_VelocityComponents.Add(id, comp);
}
