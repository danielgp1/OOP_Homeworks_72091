#pragma once
#include "String.h"
#include "Deck.h"
#include "WaterCard.h"
#include "WindCard.h"
#include "EarthCard.h"
#include "FireCard.h"
#include <fstream>

template <typename A,typename B>
class Player
{
public:
	Player();
	Player(String, size_t, size_t, Deck<A>, Deck<B>);
	void playerInfo() const;
	A drawCardFirstDeck();
	B drawCardSecondDeck();
	void getName() const;
	void increaseVictories();
	void increaseDefeats();
	void savePlayer(std::ofstream& out) const;
	//void nameReaderHelper(std::ifstream& in, String name);
	void loadPlayer(std::ifstream& in);
private:
	String name;
	size_t victories;
	size_t defeats;
	Deck<A> deck1;
	Deck<B> deck2;
};




template<typename A,typename B>
void Player<A, B>::getName() const
{
	std::cout<< this->name;
}

template<typename A, typename B>
void Player<A, B>::increaseDefeats()
{
	this->defeats++;
}

template<typename A, typename B>
void Player<A, B>::savePlayer(std::ofstream& out) const
{
	out << this->name << "\n";
	out << this->victories << "\n";
	out << this->defeats << "\n";
}

//template<typename A, typename B>
//void Player<A, B>::nameReaderHelper(std::ifstream& in, String name)
//{
//	char ch = ' ';
//	size_t counter = 0;
//	while (ch != '\n') {
//		ch = in.get();
//		if (ch != '\n' && counter < 10) {
//			name[counter++] = ch;
//		}
//	}
//	name[counter] = '\0';
//}

template<typename A, typename B>
void Player<A, B>::loadPlayer(std::ifstream& in)
{
	in >> name;
	in >> victories;
	in >> defeats;
}

template<typename A, typename B>
void Player<A, B>::increaseVictories()
{
	this->victories++;
}

template <typename A, typename B>
A Player<A, B>::drawCardFirstDeck()
{
	return deck1.drawCard();
}

template <typename A, typename B>
B Player<A, B>::drawCardSecondDeck()
{
	return deck2.drawCard();
}


template <typename A, typename B>
Player<A, B>::Player(String _name, size_t _victories, size_t _defeats, Deck<A> _deck1, Deck<B> _deck2)
{
	this->name = _name;
	this->victories = _victories;
	this->defeats = _defeats;
	this->deck1 = _deck1;
	this->deck2 = _deck2;
}


template <typename A,typename B>
Player<A,B>::Player()
{
	name = "Player";
	victories = 0;
	defeats = 0;
}

template <typename A, typename B>
void Player<A, B>::playerInfo() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Victories: " << victories << std::endl;
	std::cout << "Defeats: " << defeats << std::endl;
	std::cout << "Deck1:\n"; deck1.printCards();
	std::cout << "Deck2:\n"; deck2.printCards();
}