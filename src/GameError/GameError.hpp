#pragma once

#include "../pch.hpp"

enum class GameError {
	// component errors
	InvalidComponent,
	ComponentAlreadyAttached,
	ComponentNotAttached,

	// id errors
	InvalidID,
	InexistentID,
	IDAlreadyInUse,

	// health errors
	AmountExceedsMaxHealth,
	HealthUnderflow
};

using EmptyPossibleError = std::expected<void, GameError>;
#define NoError {}
