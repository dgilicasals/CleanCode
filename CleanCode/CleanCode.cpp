#include <iostream>

#include "CoreLoyalty.h"
#include "FuelController.h"
#include "ILoyalty.h"
#include "KrogerLoyalty.h"
#include "boost/di.hpp"
#include "Loyalty1.h"
#include "DuckLoyalty.h"

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include "fmt/format.h"

namespace di = boost::di;

int main(int argc, char** argv) {

	BOOST_LOG_TRIVIAL(info) << "Clean Code sample code" << __FILE__;

	// Dependency Injection  
	auto injector = di::make_injector(di::bind<ILoyalty>.to<KrogerLoyalty>());
	auto controller = injector.create<FuelController>();

	auto result = controller.Run();
	if (std::holds_alternative<std::string>(result)) {
		std::cout << fmt::format("Error: {}\n", std::get<std::string>(result));
	}
	else {
		std::cout << fmt::format("Result is {}\n", std::get<int>(result));
	}

	// Duck Typing
	Loyalty2 loyalty;
	DuckLoyalty duckLoyalty(loyalty);

	std::cout << "My duck rewards are " << duckLoyalty.GetRewards();

	return 0;
}
