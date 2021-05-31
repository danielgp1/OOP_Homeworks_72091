#include "Enemies.h"


Enemies::Enemies() : Mob()
{
	this->type = "enemies";
}

void Enemies::attack(Mob*& target)
{
	if (target->getType() == "enemy" || target->getType() == "enemies")
		throw(3);
	size_t size = army.getSize();
	for (size_t i = 0; i < size; ++i)
	{
		if (target->getHealth() <= 0)
			return;
		if(army[i]->getIsAlive())
			army[i]->attack(target);
	}
}

void Enemies::add(Mob*& enemy)
{
	this->army.pushBack(enemy);
}

const size_t Enemies::armyCount() const
{
	return this->army.getSize();
}

Mob*& Enemies::operator[](size_t index)
{
	return this->army[index];
}
