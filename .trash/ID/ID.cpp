#include "./ID.hpp"

ID::ID(id_number_t p_Number)
	: m_Number(p_Number)
{
	auto ok = ID::RegisterID(p_Number);
}

ID::ID()
	: m_Number(ID::GetCount() + 1)
{
	auto ok = ID::RegisterID(this->m_Number);
}

ID::~ID() {
	this->Delete();
}

id_number_t ID::GetNumber() const {
	return this->m_Number;
}

void ID::Delete() {
	// skip deleted id's
	if (this->GetNumber() == no_id)
		return;
	
	ID::UnregisterID(this->GetNumber());

	this->m_Number = no_id;
}

// static stuff
std::unordered_set<id_number_t> ID::m_IDs = {};

bool ID::IDExists(id_number_t p_Number) {
	return ID::m_IDs.contains(p_Number);
}

id_number_t ID::GetCount() {
	return (id_number_t) ID::m_IDs.size();
}

EmptyPossibleError ID::RegisterID(id_number_t p_Number) {
	if (!ID::IsValidID(p_Number))
		return std::unexpected(GameError::InvalidID);
	else if (ID::IDExists(p_Number))
		return std::unexpected(GameError::IDAlreadyInUse);

	ID::m_IDs.insert(p_Number);
	return {};
}

void ID::UnregisterID(id_number_t p_Number) {
	// skip deleted id's
	if (p_Number == no_id)
		return;

	ID::m_IDs.erase(p_Number);
}

bool ID::IsValidID(id_number_t p_Number) {
	return p_Number != no_id;
}
