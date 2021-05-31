#pragma once
#include "String.h"

class Mob
{
public:
	Mob();
	Mob(const String, double, double);
	virtual void attack(Mob*&) = 0;
	virtual void die();
	const String& getType() const;
	virtual bool getIsAlive() const;
	double getHealth() const;
	virtual void gotAttacked(double);
	virtual const size_t armyCount() const;
	virtual Mob*& operator[](size_t) ;
	virtual void add(Mob*&);
protected:
	String name;
	String type;
	double health;
	double damage;
	bool isAlive;
};