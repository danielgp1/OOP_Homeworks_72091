#pragma once

class Crypto
{
public:
	Crypto();
	Crypto(const char* _name, double _lastPrice, double _currentPrice);
	double priceDifference();
	void setName(const char* _name);
	void setLastPrice(double _lastPrice);
	void setCurrentPrice(double _currentPrice);
	const char* getName() const;
	double getLastPrice() const;
	double getCurrentPrice() const;
	void printInfo() const;
private:
	char name[30];
	double lastPrice;
	double currentPrice;

};