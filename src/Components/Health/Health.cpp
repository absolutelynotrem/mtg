#include "./Health.hpp"
#include <limits>

Components::Health::Health(health_number_t p_MaxHealth)
	: m_MaxHealthCounter(p_MaxHealth)
{}

health_number_t Components::Health::GetHealthCount() const {
	return this->m_HealthCounter;
}

EmptyPossibleError Components::Health::SetHealth(health_number_t p_HealthAmount, bool p_ClampToMax) {
	if (Health::AmountExceedsMaxHealth(p_HealthAmount) && !p_ClampToMax)
		return std::unexpected(GameError::AmountExceedsMaxHealth);

	this->m_HealthCounter = p_HealthAmount;
	return {};
}

EmptyPossibleError Components::Health::AddHealth(health_number_t p_HealthAmount, bool p_ClampToMax) {
	if (Health::AmountExceedsMaxHealth(this->GetHealthCount() + p_HealthAmount) && !p_ClampToMax) {
		return std::unexpected(GameError::AmountExceedsMaxHealth);
	}

	this->m_HealthCounter += p_HealthAmount;
	return {};
}

EmptyPossibleError Components::Health::RemoveHealth(health_number_t p_HealthAmount, bool p_ClampToZero) {
	if (Health::WillSubstractionOverflow(p_HealthAmount)) {
		// default overflow behaviour
		if (!p_ClampToZero)
			return std::unexpected(GameError::HealthUnderflow);

		// set to 0 if it underflows, according to the parameter
		this->m_HealthCounter = 0;
	} else {
		// simply subtract if its the normal case
		this->m_HealthCounter -= p_HealthAmount;
	}

	return {};
}

void Components::Health::SetMaxHealth(health_number_t p_HealthAmount) {
	this->m_MaxHealthCounter = p_HealthAmount;
}

health_number_t Components::Health::GetMaxHealthCount() const {
	return this->m_MaxHealthCounter;
}

bool Components::Health::AmountExceedsMaxHealth(health_number_t p_Number) const {
	return p_Number > this->m_MaxHealthCounter;
}

// check if substracting a specific amount from the current health
// is going to overflow the number
bool Components::Health::WillSubstractionOverflow(health_number_t p_HealthAmount) const {
	return p_HealthAmount > std::numeric_limits<health_number_t>::max() - this->m_HealthCounter;
}
