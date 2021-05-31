#pragma once
#include "Mob.h"

class Hero : public Mob
{
public:
	Hero();
	Hero(const String, double, double, int, size_t);
	void attack(Mob*&) override;
	void gotAttacked(double) override;
private:
	enum class attackType {NORMAL, SPLASH};
	attackType hit;
	int armour;

};

