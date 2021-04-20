#pragma once
#include "String.h"
class EarthCard
{
public:
	EarthCard();
	EarthCard(String, int, int);
	void printCard() const;
	EarthCard& operator=(const EarthCard& _card);
	friend std::ostream& operator <<(std::ostream& out, const EarthCard& _card);
	bool operator==(const EarthCard& _card);
	String getName() const;
	int getType() const;
	int getTotalPower() const;
	int getBasePower() const;
private:
	String name;
	int basePower;
	int bonusPower;
	int totalPower;
	int type;
};

