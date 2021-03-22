#include <iostream>
#include "Rational.h"

int main()
{
    Rational r1;
    Rational r2;
    r1.setNumerator(4);
    r1.setDenominator(2);
    r2.setNumerator(6);
    r2.setDenominator(2);
    r1.printNumber();
    r2.printNumber();
    std::cout << r1 / r2 << std::endl;
    r1 *= r2;
    r1.printNumber();
}
