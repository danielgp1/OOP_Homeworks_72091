#pragma once
#include "String.h"
class Product
{
public:
	Product();
	Product(String&, double, size_t);
	size_t getSide() const;
	size_t getDiscount() const;
	double getPrice() const;
	void setPrice(double _price);
private:
	String name;
	double price;
	size_t discount;
	enum side { HEADS, TAILS };
	side _side;
};

