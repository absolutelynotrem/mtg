#pragma once

#include "../Components/ECS.hpp"

class Entity {
private:
	EntityID id;

public:
	Entity();
	EntityID GetID();
};
