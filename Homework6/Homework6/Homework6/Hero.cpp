#include "Hero.h"
#include "Enemies.h"
Hero::Hero() : Mob()
{
	this->type = "hero";
	this->armour = 0;
	this->hit = attackType::NORMAL;
}

Hero::Hero(const String _name, double _health, double _damage, int _armour, size_t _size)
{
	this->name = _name;
	this->health = _health;
	if (health <= 0)
		throw(1);
	this->damage = _damage;
	this->armour = _armour;
	this->type = "hero";
	switch (_size)
	{
	case 1:
		this->hit = attackType::NORMAL;
		break;
	case 2:
		this->hit = attackType::SPLASH;
		break;
	default:
		this->hit = attackType::NORMAL;
		break;
	}
}

void Hero::attack(Mob*& target)
{
	if (this->isAlive == false)
		throw(2);
	if (target->getType() == "hero")
		throw(3);
	if (target->getType() == "enemies")
	{
		size_t size = target->armyCount();
		if (this->hit == attackType::SPLASH)
		{
			for (size_t i = 0; i < size; ++i)
			{
				if (target->operator[](i)->getHealth() > 0)
				{
					target->operator[](i)->gotAttacked(this->damage);
				}			
			}
		}
		else
		{
			for (size_t i = 0; i < size; ++i)
			{
				if (target->operator[](i)->getHealth() > 0)
				{
					target->operator[](i)->gotAttacked(this->damage);
					break;
				}		
			}
		}
		return;
	}
	target->gotAttacked(this->damage);
}

void Hero::gotAttacked(double attack)
{
	if (this->armour >= attack)
	{
		this->armour -= attack;
		if(this->armour == 0)
			std::cout << this->name << "'s armour has been broken!\n";
		return;
	}
	if (this->armour > 0 && this->armour < attack)
	{
		double diff = attack - armour;
		this->armour = 0;
		std::cout << this->name << "'s armour has been broken!\n";
		this->health -= diff;
		if (health <= 0)
		{
			std::cout << this->name << " has been killed!\n";
			this->die();
		}
		return;
	}
	this->health -= attack;
	if (health <= 0)
	{
		std::cout << this->name << " has been killed!\n";
		this->die();
	}
}
