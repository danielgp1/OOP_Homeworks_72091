#include <iostream>
#include "Film.h"

int main()
{
	Film f1;
	Film f2("Boom", "Daniel", 6);
	f1 = f2;
	f1.printInfo();
	return 0;
}
