#pragma once
#include <iostream>

class ILoyalty 
{
public:
	virtual ~ILoyalty() noexcept = default;
	virtual int getRewards() = 0;
	void finalize() 
	{
		std::cout << "Finalize loyalty transaction";
	};
};