#pragma once
#include <variant>
#include "Loyalty1.h"
#include "Loyalty2.h"

class DuckLoyalty
{
public:
	DuckLoyalty(std::variant<Loyalty1, Loyalty2> engine);
	int GetRewards();
private:
	std::variant<Loyalty1, Loyalty2> m_engine;
};

