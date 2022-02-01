#include "../CleanCode/FuelController.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../CleanCode/KrogerLoyalty.h"

 class MockLoyalty : public KrogerLoyalty
{
 public:
  MOCK_METHOD(int, GetRewards, (), (const, override));
};

 class FuelControllerTest : public ::testing::Test {
 protected:
  FuelController* m_fuelController;
 public:
  FuelControllerTest() {      
  };

  ~FuelControllerTest() {
    delete m_fuelController;
  }
};

 TEST_F(FuelControllerTest, Check) {
  //const MockLoyalty loyalty();
  //FuelController m_fuelController(loyalty);
  //
  //m_fuelController->Run();
  ASSERT_TRUE(true);
}