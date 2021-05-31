#pragma once
#include "Mob.h"
class Enemy : public Mob
{
public:
	Enemy();
	Enemy(const String, double, double, size_t);
	virtual void attack(Mob*&) override;
private:
	enum class size {SMALL, AVERAGE, BIG};
	size enemySize;
};

