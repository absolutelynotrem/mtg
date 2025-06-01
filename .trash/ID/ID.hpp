#pragma once

#include "../../pch.hpp"
#include "../../GameError/GameError.hpp"

using id_number_t = uint32_t;

// represents the id of a deleted instance
constexpr id_number_t no_id = 0;

class ID {
// members
private:
	id_number_t m_Number;

private:
	static std::unordered_set<id_number_t> m_IDs;

// methods
public:
	ID();
	ID(id_number_t p_Number);
	~ID();

	id_number_t GetNumber() const;
	void Delete();

public:
	static id_number_t GetCount(); // get the amount of registered id's
	static bool IDExists(id_number_t p_Number);

private:
	static std::expected<void, GameError> RegisterID(id_number_t p_Number);
	static void UnregisterID(id_number_t p_Number);
	static bool IsValidID(id_number_t p_Number);
};
