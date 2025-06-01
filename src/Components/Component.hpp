#pragma once

#include "../pch.hpp"

enum class ComponentType {
	Health,
	Velocity
};

class Component {
public:
	virtual ~Component() = default;
	virtual ComponentType GetName() const;
};
