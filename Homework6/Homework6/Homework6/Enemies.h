#pragma once
#include "Enemy.h"
#include "Vector.h"

class Enemies : public Mob
{
public:
	Enemies();
	void attack(Mob*&) override;
	void add(Mob*&);
	const size_t armyCount() const override;
	Mob*& operator[](size_t) override;
private:
	Vector<Mob*> army;
};