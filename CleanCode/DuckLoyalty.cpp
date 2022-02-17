#include "DuckLoyalty.h"

DuckLoyalty::DuckLoyalty(std::variant<Loyalty1, Loyalty2> engine) : m_engine(engine) {}

int DuckLoyalty::GetRewards()
{
	auto getEngine = [](auto& engine) { return engine.GetRewards(); };
	return std::visit(getEngine, m_engine);
}
