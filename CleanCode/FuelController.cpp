#include "FuelController.h"

const char* NO_REWARDS = "No rewards available";

FuelController::FuelController(const ILoyalty& loyalty) : m_loyalty{loyalty} {
  std::cout << "Fuel Controller\n";
}

FuelController::FuelController(const ILoyalty& loyalty, int rewards)
    : m_loyalty{loyalty} {
  std::cout << "Fuel Controller with loyalty\n";
}

FuelController::~FuelController() {

  std::cout << "Deallocation Fuel controller";
}

std::variant<std::string, int> FuelController::Run() {
  auto rewards = m_loyalty.GetRewards();

  if (rewards > 0) {
    m_loyalty.Finalize();
    return rewards;
  } else {
    return NO_REWARDS;
  }
}