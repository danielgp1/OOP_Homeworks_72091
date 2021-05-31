#include <iostream>
#include "Buyer.h"
int main()
{
	Buyer b1;
	b1.addToBUL(20);
	b1.addToBUL(50);
	b1.addToBUL(10);
	b1.addToUSA(100);
	b1.addToUSA(200);
	b1.addToUSA(1);
	b1.addToGER(5);
	b1.addToGER(50);
	b1.addToGER(20);
	b1.printCoins();
	String s1 = "milk";
	Product milk(s1, 20, 10);
	b1.buy(milk);
	return 0;
}
