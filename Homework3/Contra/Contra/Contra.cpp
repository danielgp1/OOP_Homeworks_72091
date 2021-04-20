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



template <typename A, typename B, typename C, typename D>
void playPhase(Player<A, B>& p1, Player<C, D>& p2)
{
	int i = 0;
	int j = 0;
	int victoriesPlayerOne = 0;
	int victoriesPlayerTwo = 0;
	A cardFromFirstDeckPlayer1;
	B cardFromSecondDeckPlayer1;
	C cardFromFirstDeckPlayer2;
	D cardFromSecondDeckPlayer2;

	while (victoriesPlayerOne != 5 && victoriesPlayerTwo != 5)
	{

		srand(time(NULL));
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

		std::cout << "IIIIII " << i << "  JJJJJJJJJJJJ " << j << std::endl;

		//----------------------------------------
		std::cout << "-----------------------Round " << victoriesPlayerOne + victoriesPlayerTwo + 1 << "-----------------------\n";

		if (i == 0 && j == 0)
		{
			p1.getName(); std::cout << "'s card: \n"; cardFromFirstDeckPlayer1.printCard(); std::cout << std::endl;
			p2.getName(); std::cout << "'s card: \n"; cardFromFirstDeckPlayer2.printCard(); std::cout << std::endl;
			if ((cardFromFirstDeckPlayer1.getType() == 2 && cardFromFirstDeckPlayer2.getType() == 4) || (cardFromFirstDeckPlayer1.getType() == 1 && cardFromFirstDeckPlayer2.getType() == 2) || (cardFromFirstDeckPlayer1.getType() == 3 && cardFromFirstDeckPlayer2.getType() == 1) || (cardFromFirstDeckPlayer1.getType() == 4 && cardFromFirstDeckPlayer2.getType() == 3))
			{
				if (cardFromFirstDeckPlayer1.getTotalPower() > cardFromFirstDeckPlayer2.getBasePower())
				{
					p1.getName(); std::cout << " wins the round!\n";
					victoriesPlayerOne++;
					//p1.victories++;
					//p2.defeats++;
				}
				else
				{
					p2.getName();std::cout<< " wins the round!\n";
					victoriesPlayerTwo++;
					//p2.victories++;
					//p1.defeats++;
				}
			}
			else
			{
				if (cardFromFirstDeckPlayer1.getBasePower() > cardFromFirstDeckPlayer2.getBasePower())
				{
					p1.getName(); std::cout << " wins the round!\n";
					victoriesPlayerOne++;
					//p1.victories++;
					//p2.defeats++;
				}
				else
				{
					p2.getName(); std::cout << " wins the round!\n";
					victoriesPlayerTwo++;
					//p2.victories++;
					//p1.defeats++;
				}
			}
		}


		else if (i == 0 && j == 1)
		{
			p1.getName(); std::cout << "'s card: \n"; cardFromFirstDeckPlayer1.printCard(); std::cout << std::endl;
			p2.getName(); std::cout << "'s card: \n"; cardFromSecondDeckPlayer2.printCard(); std::cout << std::endl;
			if ((cardFromFirstDeckPlayer1.getType() == 2 && cardFromSecondDeckPlayer2.getType() == 4) || (cardFromFirstDeckPlayer1.getType() == 1 && cardFromSecondDeckPlayer2.getType() == 2) || (cardFromFirstDeckPlayer1.getType() == 3 && cardFromSecondDeckPlayer2.getType() == 1) || (cardFromFirstDeckPlayer1.getType() == 4 && cardFromSecondDeckPlayer2.getType() == 3))
			{
				if (cardFromFirstDeckPlayer1.getTotalPower() > cardFromSecondDeckPlayer2.getBasePower())
				{
					p1.getName(); std::cout << " wins the round!\n";
					victoriesPlayerOne++;
					//p1.victories++;
					//p2.defeats++;
				}
				else
				{
					p2.getName(); std::cout << " wins the round!\n";
					victoriesPlayerTwo++;
					//p2.victories++;
					//p1.defeats++;
				}
			}
			else
			{
				if (cardFromFirstDeckPlayer1.getBasePower() > cardFromSecondDeckPlayer2.getBasePower())
				{
					p1.getName(); std::cout << " wins the round!\n";
					victoriesPlayerOne++;
					//p1.victories++;
					//p2.defeats++;
				}
				else
				{
					p2.getName(); std::cout << " wins the round!\n";
					victoriesPlayerTwo++;
					//p2.victories++;
					//p1.defeats++;
				}
			}
		}

		else if (i == 1 && j == 0)
		{
			p1.getName(); std::cout << "'s card: \n"; cardFromSecondDeckPlayer1.printCard(); std::cout << std::endl;
			p2.getName(); std::cout << "'s card: \n"; cardFromFirstDeckPlayer2.printCard(); std::cout << std::endl;
			if ((cardFromSecondDeckPlayer1.getType() == 2 && cardFromFirstDeckPlayer2.getType() == 4) || (cardFromSecondDeckPlayer1.getType() == 1 && cardFromFirstDeckPlayer2.getType() == 2) || (cardFromSecondDeckPlayer1.getType() == 3 && cardFromFirstDeckPlayer2.getType() == 1) || (cardFromSecondDeckPlayer1.getType() == 4 && cardFromFirstDeckPlayer2.getType() == 3))
			{
				if (cardFromSecondDeckPlayer1.getTotalPower() > cardFromFirstDeckPlayer2.getBasePower())
				{
					p1.getName(); std::cout << " wins the round!\n";
					victoriesPlayerOne++;
					//p1.victories++;
					//p2.defeats++;
				}
				else
				{
					p2.getName(); std::cout << " wins the round!\n";
					victoriesPlayerTwo++;
					//p2.victories++;
					//p1.defeats++;
				}
			}
			else
			{
				if (cardFromSecondDeckPlayer1.getBasePower() > cardFromFirstDeckPlayer2.getBasePower())
				{
					p1.getName(); std::cout << " wins the round!\n";
					victoriesPlayerOne++;
					//p1.victories++;
					//p2.defeats++;
				}
				else
				{
					p2.getName(); std::cout << " wins the round!\n";
					victoriesPlayerTwo++;
					//p2.victories++;
					//p1.defeats++;
				}
			}
		}


		else if (i == 1 && j == 1)
		{
			p1.getName(); std::cout << "'s card: \n"; cardFromSecondDeckPlayer1.printCard(); std::cout << std::endl;
			p2.getName(); std::cout << "'s card: \n"; cardFromSecondDeckPlayer2.printCard(); std::cout << std::endl;
			if ((cardFromSecondDeckPlayer1.getType() == 2 && cardFromSecondDeckPlayer2.getType() == 4) || (cardFromSecondDeckPlayer1.getType() == 1 && cardFromSecondDeckPlayer2.getType() == 2) || (cardFromSecondDeckPlayer1.getType() == 3 && cardFromSecondDeckPlayer2.getType() == 1) || (cardFromSecondDeckPlayer1.getType() == 4 && cardFromSecondDeckPlayer2.getType() == 3))
			{
				if (cardFromSecondDeckPlayer1.getTotalPower() > cardFromSecondDeckPlayer2.getBasePower())
				{
					p1.getName(); std::cout << " wins the round!\n";
					victoriesPlayerOne++;
					//p1.victories++;
					//p2.defeats++;
				}
				else
				{
					p2.getName(); std::cout << " wins the round!\n";
					victoriesPlayerTwo++;
					//p2.victories++;
					//p1.defeats++;
				}
			}
			else
			{
				if (cardFromSecondDeckPlayer1.getBasePower() > cardFromSecondDeckPlayer2.getBasePower())
				{
					p1.getName(); std::cout << " wins the round!\n";
					victoriesPlayerOne++;
					//p1.victories++;
					//p2.defeats++;
				}
				else
				{
					p2.getName(); std::cout << " wins the round!\n";
					victoriesPlayerTwo++;
					//p2.victories++;
					//p1.defeats++;
				}
			}
		}

	}

}



int main()
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

    Player<WindCard, FireCard> p1("Daniel", 0, 0, deck1, deck2);
    Player<WaterCard, EarthCard> p2("David", 0, 0, deck3, deck4);


	playPhase(p1, p2);
    return 0;
}
