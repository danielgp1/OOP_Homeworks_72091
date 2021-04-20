#include <iostream>
#include "String.h"
#include "Deck.h"
#include "WaterCard.h"
#include "WindCard.h"
#include "FireCard.h"
#include "EarthCard.h"
#include "Player.h"
#include <stdlib.h>
#include <time.h>
#include <fstream>



template<typename A,typename B>
bool isContra(A card1, B card2)
{
	if ((card1.getType() == 2 && card2.getType() == 4) || (card1.getType() == 1 && card2.getType() == 2) ||
		(card1.getType() == 3 && card2.getType() == 1) || (card1.getType() == 4 && card2.getType() == 3))
		return true;
	return false;
}



template <typename A, typename B, typename C, typename D>
void playPhase(Player<A, B>& p1, Player<C, D>& p2)
{
	std::ofstream out1("Player1.txt");
	std::ofstream out2("Player2.txt");

	int i = 0;
	int j = 0;
	int victoriesPlayerOne = 0;
	int victoriesPlayerTwo = 0;
	A cardFromFirstDeckPlayer1;
	B cardFromSecondDeckPlayer1;
	C cardFromFirstDeckPlayer2;
	D cardFromSecondDeckPlayer2;
	srand(time(NULL));
	while (victoriesPlayerOne != 5 && victoriesPlayerTwo != 5)
	{

		i = rand() % 2;
		if (i == 0)
		{
			cardFromFirstDeckPlayer1 = p1.drawCardFirstDeck();
		}
		else
		{
			cardFromSecondDeckPlayer1 = p1.drawCardSecondDeck();
		}
		j = rand() % 2;
		if (j == 0)
		{
			cardFromFirstDeckPlayer2 = p2.drawCardFirstDeck();
		}
		else
		{
			cardFromSecondDeckPlayer2 = p2.drawCardSecondDeck();
		}

		std::cout << "-----------------------Round " << victoriesPlayerOne + victoriesPlayerTwo + 1 << "-----------------------\n";

		if (i == 0 && j == 0)
		{
			p1.getName(); std::cout << "'s card: \n"; cardFromFirstDeckPlayer1.printCard(); std::cout << std::endl;
			p2.getName(); std::cout << "'s card: \n"; cardFromFirstDeckPlayer2.printCard(); std::cout << std::endl;
			if (isContra(cardFromFirstDeckPlayer1, cardFromFirstDeckPlayer2))
			{
				std::cout << "CONTRA!\n";
				if (cardFromFirstDeckPlayer1.getTotalPower() > cardFromFirstDeckPlayer2.getBasePower())
				{
					p1.getName(); std::cout << " wins the round!\n";
					victoriesPlayerOne++;
			
				}
				else
				{
					p2.getName();std::cout<< " wins the round!\n";
					victoriesPlayerTwo++;
				
				}
			}
			else
			{
				if (cardFromFirstDeckPlayer1.getBasePower() > cardFromFirstDeckPlayer2.getBasePower())
				{
					p1.getName(); std::cout << " wins the round!\n";
					victoriesPlayerOne++;
					
				}
				else
				{
					p2.getName(); std::cout << " wins the round!\n";
					victoriesPlayerTwo++;
					
				}
			}
		}


		else if (i == 0 && j == 1)
		{
			p1.getName(); std::cout << "'s card: \n"; cardFromFirstDeckPlayer1.printCard(); std::cout << std::endl;
			p2.getName(); std::cout << "'s card: \n"; cardFromSecondDeckPlayer2.printCard(); std::cout << std::endl;
			if (isContra(cardFromFirstDeckPlayer1, cardFromSecondDeckPlayer2))
			{
				std::cout << "CONTRA!\n";
				if (cardFromFirstDeckPlayer1.getTotalPower() > cardFromSecondDeckPlayer2.getBasePower())
				{
					p1.getName(); std::cout << " wins the round!\n";
					victoriesPlayerOne++;
					
				}
				else
				{
					p2.getName(); std::cout << " wins the round!\n";
					victoriesPlayerTwo++;
					
				}
			}
			else
			{
				if (cardFromFirstDeckPlayer1.getBasePower() > cardFromSecondDeckPlayer2.getBasePower())
				{
					p1.getName(); std::cout << " wins the round!\n";
					victoriesPlayerOne++;
					
				}
				else
				{
					p2.getName(); std::cout << " wins the round!\n";
					victoriesPlayerTwo++;
					
				}
			}
		}

		else if (i == 1 && j == 0)
		{
			p1.getName(); std::cout << "'s card: \n"; cardFromSecondDeckPlayer1.printCard(); std::cout << std::endl;
			p2.getName(); std::cout << "'s card: \n"; cardFromFirstDeckPlayer2.printCard(); std::cout << std::endl;
			if (isContra(cardFromSecondDeckPlayer1, cardFromFirstDeckPlayer2))
			{
				std::cout << "CONTRA!\n";
				if (cardFromSecondDeckPlayer1.getTotalPower() > cardFromFirstDeckPlayer2.getBasePower())
				{
					p1.getName(); std::cout << " wins the round!\n";
					victoriesPlayerOne++;
					
				}
				else
				{
					p2.getName(); std::cout << " wins the round!\n";
					victoriesPlayerTwo++;
					
				}
			}
			else
			{
				if (cardFromSecondDeckPlayer1.getBasePower() > cardFromFirstDeckPlayer2.getBasePower())
				{
					p1.getName(); std::cout << " wins the round!\n";
					victoriesPlayerOne++;
					
				}
				else
				{
					p2.getName(); std::cout << " wins the round!\n";
					victoriesPlayerTwo++;
					
				}
			}
		}


		else if (i == 1 && j == 1)
		{
			p1.getName(); std::cout << "'s card: \n"; cardFromSecondDeckPlayer1.printCard(); std::cout << std::endl;
			p2.getName(); std::cout << "'s card: \n"; cardFromSecondDeckPlayer2.printCard(); std::cout << std::endl;
			if (isContra(cardFromSecondDeckPlayer1, cardFromSecondDeckPlayer2))
			{
				std::cout << "CONTRA!\n";
				if (cardFromSecondDeckPlayer1.getTotalPower() > cardFromSecondDeckPlayer2.getBasePower())
				{
					p1.getName(); std::cout << " wins the round!\n";
					victoriesPlayerOne++;
					
				}
				else
				{
					p2.getName(); std::cout << " wins the round!\n";
					victoriesPlayerTwo++;
					
				}
			}
			else
			{
				if (cardFromSecondDeckPlayer1.getBasePower() > cardFromSecondDeckPlayer2.getBasePower())
				{
					p1.getName(); std::cout << " wins the round!\n";
					victoriesPlayerOne++;
					
				}
				else
				{
					p2.getName(); std::cout << " wins the round!\n";
					victoriesPlayerTwo++;
					
				}
			}
		}

	}
	std::cout << std::endl<< std::endl;
	std::cout << "----------------------GAME OVER!----------------------" << std::endl;
	if (victoriesPlayerOne == 5)
	{
		std::cout << "WINNER: "; p1.getName(); std::cout << std::endl;
		p1.increaseVictories();
		p2.increaseDefeats();
		if (out1.is_open())
		{
			p1.savePlayer(out1);
			out1.close();
		}
		else
			std::cout << "Unable to open file\n";
		if (out2.is_open())
		{
			p2.savePlayer(out2);
			out2.close();
		}
		else
			std::cout << "Unable to open file\n";
	}
	else
	{
		std::cout << "WINNER: "; p2.getName(); std::cout << std::endl;
		p2.increaseVictories();
		p1.increaseDefeats();
		if (out1.is_open())
		{
			p1.savePlayer(out1);
			out1.close();
		}
		else
			std::cout << "Unable to open file\n";
		if (out2.is_open())
		{
			p2.savePlayer(out2);
			out2.close();
		}
		else
			std::cout << "Unable to open file\n";
	}
}



int main()
{
	std::ifstream in1("Player1.txt");
	std::ifstream in2("Player2.txt");
	if (in1.is_open() && in2.is_open())
	{

		Deck<WindCard> deck1;
		WindCard v2("Yasuo", 100, 50);
		WindCard v3("Tornado", 300, 200);
		WindCard v4("Breeze", 50, 20);
		WindCard v5("Whirl", 60, 50);
		WindCard v6("Bird", 30, 10);
		deck1.addCard(v6);
		deck1.addCard(v2);
		deck1.addCard(v3);
		deck1.addCard(v4);
		deck1.addCard(v5);

		Deck<FireCard> deck2;
		FireCard f2("Brand", 110, 33);
		FireCard f3("Alistar", 15, 100);
		FireCard f4("Darius", 350, 40);
		FireCard f5("Sona", 62, 140);
		FireCard f6("Zed", 420, 15);
		deck2.addCard(f6);
		deck2.addCard(f2);
		deck2.addCard(f3);
		deck2.addCard(f4);
		deck2.addCard(f5);

		Deck<WaterCard> deck3;
		WaterCard w2("Zac", 125, 34);
		WaterCard w3("Draven", 65, 120);
		WaterCard w4("Rek'Sai", 42, 138);
		WaterCard w5("Nocturne", 220, 300);
		WaterCard w6("Jinx", 176, 42);
		deck3.addCard(w6);
		deck3.addCard(w2);
		deck3.addCard(w3);
		deck3.addCard(w4);
		deck3.addCard(w5);

		Deck<EarthCard> deck4;
		EarthCard e2("Maokai", 69, 184);
		EarthCard e3("Malphite", 135, 67);
		EarthCard e4("Braum", 213, 32);
		EarthCard e5("Shen", 153, 53);
		EarthCard e6("Ramus", 80, 222);
		deck4.addCard(e6);
		deck4.addCard(e2);
		deck4.addCard(e3);
		deck4.addCard(e4);
		deck4.addCard(e5);

		Player<WindCard, FireCard> p1("David", 0, 0, deck1, deck2);
		Player<WaterCard, EarthCard> p2("Daniel", 0, 0, deck3, deck4);

		p1.loadPlayer(in1);
		p2.loadPlayer(in2);


		std::cout << "CONTRA MATCH\n\n";
		playPhase(p1, p2);

		in1.close();
		in2.close();
	}
	else
	{
		std::cout << "Unable to open files!\n";
	}
    return 0;
}
