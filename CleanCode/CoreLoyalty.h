#pragma once
#include "ILoyalty.h"

class CoreLoyalty : public ILoyalty
{
public:
	int GetRewards() const override;
};

