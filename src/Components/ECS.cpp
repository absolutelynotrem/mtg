#include "./ECS.hpp"
#include <expected>

EntityID ECS::m_LastID = 0;

EntityID ECS::AssignID() {
	return ECS::m_LastID++;
}

ComponentManager& ECS::Manager() {
	return this->m_Manager;
}
