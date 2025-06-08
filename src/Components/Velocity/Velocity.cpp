#include "./Velocity.hpp"

Components::Velocity::Velocity(float p_X, float p_Y)
	: m_X(p_X),
	  m_Y(p_Y)
{}

Components::Velocity::Velocity()
	: m_X(0),
	  m_Y(0)
{}

float Components::Velocity::GetX() const {
	return this->m_X;
}

float Components::Velocity::GetY() const {
	return this->m_Y;
}

Components::Velocity Components::Velocity::Normalize() {
	float mag = std::sqrt(this->m_X * this->m_X + this->m_Y * this->m_Y);

	return Components::Velocity(this->m_X / mag, this->m_Y / mag);
}
