#pragma once

#include "../../pch.hpp"
#include "../../GameError/GameError.hpp"
#include "../Component.hpp"

using health_number_t = uint8_t;

namespace Components {

class Health {
// members
private:
	health_number_t m_HealthCounter = 0;
	health_number_t m_MaxHealthCounter = 0;

// methods
public:
	Health(health_number_t p_MaxHealth);

	health_number_t GetHealthCount() const;
	EmptyPossibleError SetHealth(health_number_t p_HealthAmount, bool p_ClampHealthToMax = true);
	EmptyPossibleError AddHealth(health_number_t p_HealthAmount, bool p_ClampHealthToMax = true);
	EmptyPossibleError RemoveHealth(health_number_t p_HealthAmount, bool p_ClampToZero = true);

	void SetMaxHealth(health_number_t p_HealthAmount);
	health_number_t GetMaxHealthCount() const;

private:
	bool AmountExceedsMaxHealth(health_number_t p_Number) const;
	bool WillSubstractionOverflow(health_number_t p_HealthAmount) const;
};

}
