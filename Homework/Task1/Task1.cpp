#include <iostream>
#include "Crypto.h"

int main()
{
    Crypto c1("Bitcoin", 30000, 50000);
    std::cout << c1.priceDifference() << " %" << std::endl;
    c1.printInfo();
    return 0;
}
