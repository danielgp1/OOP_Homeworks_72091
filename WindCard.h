#pragma once
#include "String.h"
class WindCard
{
public:
	WindCard();
	WindCard(String, int, int);
	void printCard() const;
	WindCard& operator=(const WindCard& _card);
	friend std::ostream& operator <<(std::ostream& out, const WindCard& _card);
	bool operator==(const WindCard& _card);
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

