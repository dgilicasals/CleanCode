#include "../CleanCode/CoreLoyalty.h"
#include "gtest/gtest.h"

class CoreLoyaltyTest : public ::testing::Test {
 protected:
  CoreLoyalty m_CoreLoyalty{};
};

TEST_F(CoreLoyaltyTest, CoreDefaultRewards) {
  auto rewards = m_CoreLoyalty.GetRewards();
  EXPECT_EQ(0, rewards);
}