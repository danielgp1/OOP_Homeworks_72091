#pragma once
#include "Coin.h"
#include "Wallet.h"
#include "Product.h"
#include "BulgarianCoin.h"
#include "AmericanCoin.h"
#include "GermanCoin.h"
class Buyer
{
public:
	void addToBUL(size_t);
	void addToUSA(size_t);
	void addToGER(size_t);

	void removeFromBUL(size_t);
	void removeFromUSA(size_t);
	void removeFromGER(size_t);

	void printCoins() const;

	void buy(Product);
private:
	Wallet<BulgarianCoin> BULcoins;
	Wallet<AmericanCoin> USAcoins;
	Wallet<GermanCoin> GERcoins;
};