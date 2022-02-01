#include <iostream>

#include "CoreLoyalty.h"
#include "FuelController.h"
#include "ILoyalty.h"
#include "KrogerLoyalty.h"
#include "boost/di.hpp"

namespace di = boost::di;

int main(int argc, char** argv) {
  auto injector = di::make_injector(di::bind<ILoyalty>.to<KrogerLoyalty>());
  auto controller = injector.create<FuelController>();

  auto result = controller.Run();
  if (std::holds_alternative<std::string>(result)) {
    std::cout << "Error:  " << std::get<std::string>(result);
  } else {
    std::cout << "Result is " << std::get<int>(result);
  }
}