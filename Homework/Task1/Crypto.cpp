#include <iostream>
#include <cmath>
#include "Crypto.h"
#include <cstring>
Crypto::Crypto()
{
	strcpy_s(this->name, 5, "none");
	lastPrice = 0;
	currentPrice = 0;
}

Crypto::Crypto(const char* _name, double _lastPrice, double _currentPrice)
{
	strcpy_s(this->name, strlen(_name) + 1, _name);
	this->lastPrice = _lastPrice;
	this->currentPrice = _currentPrice;
}

double Crypto::priceDifference()
{
	double difference = (double)(this->currentPrice - this->lastPrice) / abs(this->lastPrice);
	return ceil((100.0 * difference) * 100.0) / 100.0;
}

void Crypto::setName(const char* _name)
{
	strcpy_s(this->name, strlen(_name) + 1, _name);
}

void Crypto::setLastPrice(double _lastPrice)
{
	this->lastPrice = _lastPrice;
}

void Crypto::setCurrentPrice(double _currentPrice)
{
	this->currentPrice = _currentPrice;
}

const char* Crypto::getName() const
{
	return this->name;
}

double Crypto::getLastPrice() const
{
	return this->lastPrice;
}

double Crypto::getCurrentPrice() const
{
	return this->currentPrice;
}

void Crypto::printInfo() const
{
	std::cout << this->name << std::endl;
	std::cout << this->lastPrice << std::endl;
	std::cout << this->currentPrice << std::endl;
}
