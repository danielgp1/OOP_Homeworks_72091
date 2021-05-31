#pragma once
#include "Coin.h"
class BulgarianCoin : public Coin
{
public:
	BulgarianCoin();
	BulgarianCoin(size_t);
	void flip() override;
};