#pragma once
#include <iostream>

class ILoyalty 
{
public:
	virtual ~ILoyalty() noexcept = default;
	virtual int GetRewards() const = 0;	
};