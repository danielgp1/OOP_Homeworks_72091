#include "Coin.h"

void Coin::flip()
{
}

void Coin::evaluate()
{
	if (!strcmp(this->nationality,"Bulgarian"))
	{
		std::cout << this->value << " BulgarianCoin = " << 3 * this->value << " AmericanCoin\n";
		std::cout << this->value << " BulgarianCoin = " << 6 * this->value << " GermanCoin\n";
	}
	else if (!strcmp(this->nationality, "American"))
	{
		std::cout << this->value << " AmericanCoin = " << this->value / 3 << " BulgarianCoin\n";
		std::cout << this->value << " AmericanCoin = " << 2.5 * this->value << " GermanCoin\n";
	}
	else
	{
		std::cout << this->value << " GermanCoin = " << this->value / 6 << " BulgarianCoin\n";
		std::cout << this->value << " GermanCoin = " << 2 * this->value / 5 << " AmericanCoin\n";
	}
}

void Coin::print() const
{
	std::cout << "Nationality: " << this->nationality << std::endl;
	std::cout << "Side: ";
	if (this->_side == 0)
		std::cout << "HEADS\n";
	else
		std::cout << "TAILS\n";
	std::cout << "Value: " << this->value << std::endl;
}

Coin::Coin()
{
	this->_side = HEADS;
	this->value = 0;
	this->nationality = new char[20];
	strcpy_s(this->nationality, 20, "None");
}

Coin::Coin(size_t _value) : Coin()
{
	if (_value != 1 && _value != 2 && _value != 5 && _value != 10 && _value != 20 && _value != 50 && _value != 100 && _value != 200)
	{
		std::cout << "Value must be: 1 | 2 | 5 | 10 | 20 | 50 | 100 | 200 !\n";
		std::cout << "Value has been automatically set to 1!\n";
		this->value = 1;
	}
	else
		this->value = _value;
}

size_t Coin::getValue() const
{
	return this->value;
}

size_t Coin::getSide() const
{
	return this->_side;
}

Coin::~Coin()
{
	this->erase();
}

Coin::Coin(const Coin& otherCoin)
{
	this->copy(otherCoin);
}

Coin& Coin::operator=(const Coin& otherCoin)
{
	if (this != &otherCoin)
	{
		this->erase();
		this->copy(otherCoin);
	}
	return *this;
}

void Coin::copy(const Coin& otherCoin)
{
	this->_side = otherCoin._side;
	this->value = otherCoin.value;
	this->nationality = new char[strlen(otherCoin.nationality) + 1];
	strcpy_s(this->nationality, strlen(otherCoin.nationality) + 1, otherCoin.nationality);
}

void Coin::erase()
{
	delete[] this->nationality;
}
