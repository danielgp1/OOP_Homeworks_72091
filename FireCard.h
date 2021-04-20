#pragma once
#include "String.h"
class FireCard
{
public:
	FireCard();
	FireCard(String, int, int);
	void printCard() const;
	FireCard& operator=(const FireCard& _card);
	friend std::ostream& operator <<(std::ostream& out, const FireCard& _card);
	bool operator==(const FireCard& _card);
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

