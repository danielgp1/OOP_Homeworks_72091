#include "Enemy.h"

Enemy::Enemy() : Mob()
{
	this->type = "enemy";
	this->enemySize = size::SMALL;
}

Enemy::Enemy(const String _name, double _health, double _damage, size_t _size)
{
	this->name = _name;
	this->health = _health;
	if (health <= 0)
		throw(1);
	this->damage = _damage;
	this->type = "enemy";
	switch (_size)
	{
	case 1:
		this->enemySize = size::SMALL;
		break;
	case 2:
		this->enemySize = size::AVERAGE;
		this->damage *= 1.5;
		break;
	case 3:
		this->enemySize = size::BIG;
		this->damage *= 2;
		break;
	default:
		this->enemySize = size::SMALL;
		break;
	}
}

void Enemy::attack(Mob*& mob)
{
	if (this->isAlive == false)
		throw(2);
	if (mob->getType() == "enemy" || mob->getType() == "enemies")
		throw(3);
	mob->gotAttacked(this->damage);
}
