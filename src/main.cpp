#include <iostream>
#include "Components/ECS.hpp"
#include "Components/Health/Health.hpp"
#include "Entity/Entity.hpp"
#include "GameError/GameError.hpp"

int main() {
	ECS ecs;
	Entity e;
	Components::Health health(100);
}
