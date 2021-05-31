#include "Product.h"

Product::Product()
{
	this->name = "Defult";
	this->price = 0;
	this->discount = 0;
	this->_side = HEADS;
}

Product::Product(String& _name, double _price, size_t _discount)
{
	this->name = _name;
	this->price = _price;
	this->discount = _discount;
	srand(time(NULL));
	int i = rand() % 2;
	if (i == 0)
	{
		this->_side = HEADS;
	}
	else
		this->_side = TAILS;
}

size_t Product::getSide() const
{
	return this->_side;
}

size_t Product::getDiscount() const
{
	return this->discount;
}

double Product::getPrice() const
{
	return this->price;
}

void Product::setPrice(double _price) 
{
	this->price = _price;
}
