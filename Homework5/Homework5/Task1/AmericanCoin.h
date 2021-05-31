#pragma once
#include "Coin.h"
class AmericanCoin : public Coin
{
public:
	AmericanCoin();
	AmericanCoin(size_t);
	void flip() override;
};