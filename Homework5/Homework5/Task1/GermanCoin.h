#pragma once
#include "Coin.h"
class GermanCoin : public Coin
{
public:
	GermanCoin();
	GermanCoin(size_t _value);
	void flip() override;
};