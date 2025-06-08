#pragma once

#include "../../pch.hpp"

namespace Components {
class Velocity {
	// members
private:
	float m_X, m_Y;

// methods
public:
	Velocity();
	Velocity(float p_X, float p_Y);

	float GetX() const;
	float GetY() const;

	Components::Velocity Normalize();
};
}
