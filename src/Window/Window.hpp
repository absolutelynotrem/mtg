#pragma once

#include "../pch.hpp"

class Window {
private:
	uint8_t m_Width, m_Height;

public:
	uint8_t GetWidth();
	uint8_t GetHeight();
};
