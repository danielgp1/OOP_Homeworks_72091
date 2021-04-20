#include "FireCard.h"

FireCard::FireCard()
{
	name = "Fire";
	basePower = 0;
	bonusPower = 0;
	totalPower = 0;
	type = 2;
}

FireCard::FireCard(String _name, int _basePower, int _bonusPower)
{
	this->name = _name;
	this->basePower = _basePower;
	this->bonusPower = _bonusPower;
	this->totalPower = this->basePower + this->bonusPower;
	this->type = 2;

}

void FireCard::printCard() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Base Power: " << basePower << std::endl;
	std::cout << "Bonus Power: " << bonusPower << std::endl;
	std::cout << "Total Power: " << totalPower << std::endl;
	std::cout << "Type: " << type << std::endl;
}

FireCard& FireCard::operator=(const FireCard& _card)
{
	if (this != &_card)
	{
		this->name = _card.name;
		this->bonusPower = _card.bonusPower;
		this->basePower = _card.basePower;
		this->totalPower = _card.totalPower;
		this->type = _card.type;
	}
	return *this;
}

bool FireCard::operator==(const FireCard& _card)
{
	 return this->name == _card.name;
}

String FireCard::getName() const
{
	return name;
}

int FireCard::getType() const
{
	return this->type;
}

int FireCard::getTotalPower() const
{
	return this->totalPower;
}

int FireCard::getBasePower() const
{
	return this->basePower;
}

std::ostream& operator<<(std::ostream& out, const FireCard& _card)
{
	out << "Name: " << _card.name << std::endl << "Base Power: " << _card.basePower << std::endl << "Bonus Power: " << _card.bonusPower << std::endl << "Total Power: " << _card.totalPower << std::endl << "Type: " << _card.type << std::endl;
	return out;
}
