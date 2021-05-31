
#include <iostream>
#include "Enemies.h"
#include "Hero.h"
int main()
{
    try
    {
        Mob* m1 = new Enemy("Stenli", 150, 140, 3);
        Mob* m2 = new Enemy("Beray", 15, 10, 1);
        Mob* m3 = new Enemy("Milen", 80, 50, 2);
        Mob* m4 = new Enemy("Maria", 1, 1000, 1);
        Mob* m5 = new Enemy("Ali", 100, 70, 3);

        Mob* army = new Enemies();
        army->add(m1);
        army->add(m2);
        army->add(m3);
        army->add(m4);
        army->add(m5);

        Mob* m6 = new Hero("Daniel", 200, 80, 100, 2);
        m6->attack(army);
    }
    catch (int number)
    {
        switch (number)
        {
        case 1:
            std::cout << "Health must be a positive number!\n";
            break;
        case 2:
            std::cout << "The mob is already dead!\n";
            break;
        case 3:
            std::cout << "Can't attack mobs of the same type\n";
            break;
        default:
            break;
        }
    }   
    return 0;
}
