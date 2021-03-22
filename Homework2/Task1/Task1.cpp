#include <iostream>
#include "String.h"
int main()
{
    String s1;
    s1.add('a');
    s1.add('a');
    s1.add('a');
    s1.add('b');
    String s2;
    s2.add('c');
    s2.add('d');
    s2.add('d');
    s2.add('d');
    s2.add('d');
    s2.add('d');
    s2.add('d');
    s2.add('d');
    s1.printData();
    s2.printData();
    s1 += s2;
    s1.printData();
    String s3;
    s3.add('c');
    s3.add('d');
    s3.add('d');
    s3.add('d');
    s3.add('d');
    s3.add('d');
    s3.add('d');
    s3.add('d');
    bool b = s2 == s3;
    bool b2 = s2 != s3;
    std::cout << std::boolalpha << b << std:: endl;
    std::cout << std::boolalpha << b2 << std::endl;
    std::cout << s1[16] << std:: endl;
}
