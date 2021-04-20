#pragma once
#include "Player.h"
#include "Deck.h"
#include "WaterCard.h"
template <typename A,typename B,typename C,typename D>
class Match
{
public:
	void playPhase(Player<A, B>& p1, Player<C, D>& p2)
	{
		A cardFromFirstDeckPlayer1;
		B cardFromSecondDeckPlayer1;
		C cardFromFirstDeckPlayer2;
		D cardFromSecondDeckPlayer2;

		while (p1.victories == 5 || p2.victories == 5)
		{

			srand(time(NULL));
			int i = rand() % 2;
			if (i == 0)
			{
				cardFromFirstDeckPlayer1 = p1.drawCardFirstDeck();
			}
			else
			{
				cardFromSecondDeckPlayer1 = p1.drawCardSecondDeck();
			}
			int j = rand() % 2;
			if (j == 0)
			{
				cardFromFirstDeckPlayer2 = p2.drawCardFirstDeck();
			}
			else
			{
				cardFromSecondDeckPlayer2 = p2.drawCardSecondDeck();
			}
			
			//----------------------------------------
			std::cout << "-----------------------Round " << p1.victories + p2.victories + 1 << "-----------------------\n";

			if (i == 0 && j == 0)
			{
				std::cout << p1.name << "'s card: \n" << cardFromFirstDeckPlayer1.printCard() << std::endl;
				std::cout << p2.name << "'s card: \n" << cardFromFirstDeckPlayer2.printCard() << std::endl;
				if ((cardFromFirstDeckPlayer1.getType() == 2 && cardFromFirstDeckPlayer2.getType() == 4) || (cardFromFirstDeckPlayer1.getType() == 1 && cardFromFirstDeckPlayer2.getType() == 2) || (cardFromFirstDeckPlayer1.getType() == 3 && cardFromFirstDeckPlayer2.getType() == 1) || (cardFromFirstDeckPlayer1.getType() == 4 && cardFromFirstDeckPlayer2.getType() == 3))
				{
					if (cardFromFirstDeckPlayer1.getTotalPower() > cardFromFirstDeckPlayer2.getTotalPower())
					{
						std::cout << p1.name << " wins the round!\n";
						p1.victories++;
						p2.defeats++;
					}
					else
					{
						std::cout << p2.name << " wins the round!\n";
						p2.victories++;
						p1.defeats++;
					}
				}
				else
				{
					if (cardFromFirstDeckPlayer1.getBasePower() > cardFromFirstDeckPlayer2.getBasePower())
					{
						std::cout << p1.name << " wins the round!\n";
						p1.victories++;
						p2.defeats++;
					}
					else
					{
						std::cout << p2.name << " wins the round!\n";
						p2.victories++;
						p1.defeats++;
					}
				}
			}
			

			if (i == 0 && j == 1)
			{
				std::cout << p1.name << "'s card: \n" << cardFromFirstDeckPlayer1.printCard() << std::endl;
				std::cout << p2.name << "'s card: \n" << cardFromSecondDeckPlayer2.printCard() << std::endl;
				if ((cardFromFirstDeckPlayer1.getType() == 2 && cardFromSecondDeckPlayer2.getType() == 4) || (cardFromFirstDeckPlayer1.getType() == 1 && cardFromSecondDeckPlayer2.getType() == 2) || (cardFromFirstDeckPlayer1.getType() == 3 && cardFromSecondDeckPlayer2.getType() == 1) || (cardFromFirstDeckPlayer1.getType() == 4 && cardFromSecondDeckPlayer2.getType() == 3))
				{
					if (cardFromFirstDeckPlayer1.getTotalPower() > cardFromSecondDeckPlayer2.getTotalPower())
					{
						std::cout << p1.name << " wins the round!\n";
						p1.victories++;
						p2.defeats++;
					}
					else
					{
						std::cout << p2.name << " wins the round!\n";
						p2.victories++;
						p1.defeats++;
					}
				}
				else
				{
					if (cardFromFirstDeckPlayer1.getBasePower() > cardFromSecondDeckPlayer2.getBasePower())
					{
						std::cout << p1.name << " wins the round!\n";
						p1.victories++;
						p2.defeats++;
					}
					else
					{
						std::cout << p2.name << " wins the round!\n";
						p2.victories++;
						p1.defeats++;
					}
				}
			}


			
			if (i == 1 && j == 0)
			{
				std::cout << p1.name << "'s card: \n" << cardFromSecondDeckPlayer1.printCard() << std::endl;
				std::cout << p2.name << "'s card: \n" << cardFromFirstDeckPlayer2.printCard() << std::endl;
				if ((cardFromSecondDeckPlayer1.getType() == 2 && cardFromFirstDeckPlayer2.getType() == 4) || (cardFromSecondDeckPlayer1.getType() == 1 && cardFromFirstDeckPlayer2.getType() == 2) || (cardFromSecondDeckPlayer1.getType() == 3 && cardFromFirstDeckPlayer2.getType() == 1) || (cardFromSecondDeckPlayer1.getType() == 4 && cardFromFirstDeckPlayer2.getType() == 3))
				{
					if (cardFromSecondDeckPlayer1.getTotalPower() > cardFromFirstDeckPlayer2.getTotalPower())
					{
						std::cout << p1.name << " wins the round!\n";
						p1.victories++;
						p2.defeats++;
					}
					else
					{
						std::cout << p2.name << " wins the round!\n";
						p2.victories++;
						p1.defeats++;
					}
				}
				else
				{
					if (cardFromSecondDeckPlayer1.getBasePower() > cardFromFirstDeckPlayer2.getBasePower())
					{
						std::cout << p1.name << " wins the round!\n";
						p1.victories++;
						p2.defeats++;
					}
					else
					{
						std::cout << p2.name << " wins the round!\n";
						p2.victories++;
						p1.defeats++;
					}
				}
			}


			if (i == 1 && j == 1)
			{
				std::cout << p1.name << "'s card: \n" << cardFromSecondDeckPlayer1.printCard() << std::endl;
				std::cout << p2.name << "'s card: \n" << cardFromSecondDeckPlayer2.printCard() << std::endl;
				if ((cardFromSecondDeckPlayer1.getType() == 2 && cardFromSecondDeckPlayer2.getType() == 4) || (cardFromSecondDeckPlayer1.getType() == 1 && cardFromSecondDeckPlayer2.getType() == 2) || (cardFromSecondDeckPlayer1.getType() == 3 && cardFromSecondDeckPlayer2.getType() == 1) || (cardFromSecondDeckPlayer1.getType() == 4 && cardFromSecondDeckPlayer2.getType() == 3))
				{
					if (cardFromSecondDeckPlayer1.getTotalPower() > cardFromSecondDeckPlayer2.getTotalPower())
					{
						std::cout << p1.name << " wins the round!\n";
						p1.victories++;
						p2.defeats++;
					}
					else
					{
						std::cout << p2.name << " wins the round!\n";
						p2.victories++;
						p1.defeats++;
					}
				}
				else
				{
					if (cardFromSecondDeckPlayer1.getBasePower() > cardFromSecondDeckPlayer2.getBasePower())
					{
						std::cout << p1.name << " wins the round!\n";
						p1.victories++;
						p2.defeats++;
					}
					else
					{
						std::cout << p2.name << " wins the round!\n";
						p2.victories++;
						p1.defeats++;
					}
				}
			}

		}

	}
private:
};

