#include "Mob.h"
#include "Enemies.h"
Mob::Mob()
{
    this->name = "Default";
    this->health = 0;
    this->damage = 0;
    this->isAlive = true;
}

Mob::Mob(const String _name, double _health, double _damage)
{
    this->name = _name;
    this->health = _health;
    this->damage = _damage;
    this->isAlive = true;
}

void Mob::die()
{
    this->isAlive = false;
}

const String& Mob::getType() const
{
    return this->type;
}

bool Mob::getIsAlive() const
{
    return this->isAlive;
}

double Mob::getHealth() const
{
    return this->health;
}

void Mob::gotAttacked(double attack)
{
    this->health -= attack;
    if (health <= 0)
    {
        std::cout << this->name << " has been killed!\n";
        this->die();
    }   
}

const size_t Mob::armyCount() const
{
    return 0;
}

Mob*& Mob::operator[](size_t index)
{
    Mob* mob = new Enemy();
    return mob;
}

void Mob::add(Mob*&)
{
}
