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

// instead of throwing errors, id like to use std::expected
// in a way that is similar to rust's Option type
using EmptyPossibleError = std::expected<void, GameError>;
#define NoError {}
