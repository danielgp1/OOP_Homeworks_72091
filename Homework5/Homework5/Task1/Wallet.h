#pragma once
#include "Coin.h"
#include "Vector.h"

template <typename T>
class Wallet
{
public:
	enum side { HEADS, TAILS };
	void addCoin(size_t);
	void removeCoin(size_t);
	void getValues() const;
	size_t totalBalance() const;
	void tryToBuy(size_t);
protected:
	Vector<T> coins;
};

template<typename T>
void Wallet<T>::addCoin(size_t value)
{
	T c1(value);
	coins.pushBack(c1);
}

template<typename T>
void Wallet<T>::removeCoin(size_t _value)
{
	size_t size = coins.getSize();
	int index = -1;
	for (size_t i = 0; i < size; ++i)
	{
		if (coins[i].getValue() == _value)
		{
			index = i;
			break;
		}
	}
	if (index == -1)
	{
		std::cout << "No coin with that value!\n";
		return;
	}
	coins.removeAt(index);
	std::cout << "You have paid " << _value << "!\n";
}

template<typename T>
void Wallet<T>::getValues() const
{
	size_t size = coins.getSize();
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << coins[i].getValue();
		if (i == size - 1)
			continue;
		else
			std::cout << " | ";
	}
	std::cout << std::endl;
}

template<typename T>
inline size_t Wallet<T>::totalBalance() const
{
	size_t balance = 0;
	size_t size = coins.getSize();
	for (size_t i = 0; i < size; ++i)
	{
		balance += coins[i].getValue();
	}
	return balance;
}

template<typename T>
inline void Wallet<T>::tryToBuy(size_t price)
{
	size_t index = -1;
	for (size_t i = 0; i < coins.getSize(); ++i)
	{
		if (coins[i].getValue() == price)
		{
			index = i;
			break;
		}
	}
	if (index == -1)
	{
		std::cout << "Coin with that value not found!\n";
		return;
	}
	std::cout << "Product purchased!\n";
	coins.removeAt(index);
}

