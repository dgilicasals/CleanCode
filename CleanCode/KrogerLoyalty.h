#pragma once
#include "ILoyalty.h"

class KrogerLoyalty : public ILoyalty
{
public:
	int getRewards() override;
};

