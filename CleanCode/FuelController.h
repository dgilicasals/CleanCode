#pragma once
#include "ILoyalty.h"
#include <variant>

class FuelController {
private:
	const ILoyalty &m_loyalty;

public:
	FuelController(const ILoyalty &loyalty);
	FuelController(const ILoyalty &loyalty, int rewards);
	~FuelController();

	std::variant<std::string, int> Run();
};

