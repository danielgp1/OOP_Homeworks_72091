#include "GermanCoin.h"

GermanCoin::GermanCoin() : Coin()
{
	strcpy_s(this->nationality, 7, "German");
}

GermanCoin::GermanCoin(size_t _value) : GermanCoin()
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

void GermanCoin::flip()
{
	
	srand(time(NULL));
	int i = rand() % 2;
	if (i== 1)
	{
		this->_side = HEADS;
	}
	else
	this->_side = TAILS;	
}