#include <iostream>
#include "boost/di.hpp"
#include "fmt/format.h"
#include "ILoyalty.h"

#include "CoreLoyalty.h"
#include "KrogerLoyalty.h"

namespace di = boost::di;

class FuelController {
private:
	ILoyalty& m_loyalty;

public:
	FuelController(ILoyalty& loyalty) : m_loyalty{ loyalty }
	{
		std::cout << fmt::format("Fuel Controller\n");
	}

	FuelController(ILoyalty& loyalty, int rewards) : m_loyalty{ loyalty }
	{
		std::cout << fmt::format("Fuel Controller with loyalty\n");
	}

	void run() {
		auto rewards = m_loyalty.getRewards();

		if (rewards > 0)
		{
			m_loyalty.finalize();
		}
	}
};

int main(int argc, char** argv) {
	auto injector = di::make_injector(
		di::bind<ILoyalty>.to<CoreLoyalty>()
	);
	auto controller = injector.create<FuelController>();

	controller.run();

}