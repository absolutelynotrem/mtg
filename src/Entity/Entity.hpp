#pragma once

#include "../pch.hpp"

using EntityID = uint32_t;

class Entity {
private:
	EntityID id;

public:
	Entity();
	EntityID GetID();
};
