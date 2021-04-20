#pragma once
#include "String.h"
#include <cstring>
class WaterCard
{
public:
	WaterCard();
	WaterCard(String, int, int);
	void printCard() const;
	WaterCard& operator=(const WaterCard& _card);
	bool operator==(const WaterCard& _card);
	friend std::ostream& operator <<(std::ostream& out, const WaterCard& _card);
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

