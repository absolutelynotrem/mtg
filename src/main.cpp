#include <iostream>
#include "Components/ECS.hpp"
#include "Components/Health/Health.hpp"
#include "Entity/Entity.hpp"
#include "GameError/GameError.hpp"

int main() {
	ECS ecs;
	Entity e;
	Components::Health h(100);

	auto r = ecs.AttachHealthComponent(e.GetID(), h);

	if (r.error() == GameError::ComponentAlreadyAttached) {
		std::cout << "Already atttached\n";
		return 1;
	}

	auto uwu = ecs.GetHealthComponent(e.GetID())->SetHealth(100);
	if (!uwu) {
		std::cout << "UWU\n";
		return 1;
	}

	std::cout << ecs.GetHealthComponent(e.GetID())->GetHealthCount() << "\n";
}
