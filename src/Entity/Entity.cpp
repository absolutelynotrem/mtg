#include "./Entity.hpp"

Entity::Entity() {
	this->id = ECS::AssignID();
}

EntityID Entity::GetID() {
	return this->id;
}
