#include "Buyer.h"

void Buyer::addToBUL(size_t value)
{
	this->BULcoins.addCoin(value);
}

void Buyer::addToUSA(size_t value)
{
	this->USAcoins.addCoin(value);
}

void Buyer::addToGER(size_t value)
{
	this->GERcoins.addCoin(value);
}

void Buyer::removeFromBUL(size_t value)
{
	this->BULcoins.removeCoin(value);
}

void Buyer::removeFromUSA(size_t value)
{
	this->USAcoins.removeCoin(value);
}

void Buyer::removeFromGER(size_t value)
{
	this->GERcoins.removeCoin(value);
}

void Buyer::printCoins() const
{
	std::cout << "BUL\n";
	BULcoins.getValues();
	std::cout << "USA\n";
	USAcoins.getValues();
	std::cout << "GER\n";
	GERcoins.getValues();
}

void Buyer::buy(Product product)
{
	size_t discount = product.getDiscount();
	double price = product.getPrice();
	srand(time(NULL));
	int i = rand() % 3;
	if (i == 0)
	{
		std::cout << "Prices are in BulgarianCoin!\n";
		std::cout << "Product price: " << price << "\n";
		BulgarianCoin b1;
		b1.flip();
		std::cout << product.getPrice() << std::endl;;
		if (b1.getSide() == product.getSide())
		{
			std::cout << "You got lucky! Product discounted by " << discount << "% !\n";
			product.setPrice(price * (100 - discount) / 100);
			price = product.getPrice();
			std::cout << "New product price: " << price << "\n";
		}
		std::cout << "Your balance of BulgarianCoin: " << BULcoins.totalBalance() << "\n";
		if (BULcoins.totalBalance() < price)
		{
			std::cout << "You can't afford this product!\n";
			return;
		}
		BULcoins.tryToBuy(price);
	}
	else if (i == 1)
	{
		AmericanCoin a1;
		a1.flip();
		product.setPrice(product.getPrice() * 3);
		price = product.getPrice();
		std::cout << "Prices have been converted to AmericanCoin!\n";
		std::cout << "Product price: " << price << "\n";
		if (a1.getSide() == product.getSide())
		{
			std::cout << "You got lucky! Product discounted by " << discount << "% !\n";
			product.setPrice(price*(100 - discount)/100);
			price = product.getPrice();
			std::cout << "New product price: " << price << "\n";
		}
		std::cout << "Your balance of AmericanCoin: " << USAcoins.totalBalance() << "\n";
		if (USAcoins.totalBalance() < price)
		{
			std::cout << "You can't afford this product!\n";
			return;
		}
		USAcoins.tryToBuy(price);
	}
	else
	{
		GermanCoin g1;
		g1.flip();
		product.setPrice(product.getPrice() * 6);
		price = product.getPrice();
		std::cout << "Prices have been converted to GermanCoin!\n";
		std::cout << "Product price: " << price << "\n";
		if (g1.getSide() == product.getSide())
		{
			std::cout << "You got lucky! Product discounted by " << product.getDiscount() << "% !\n";
			product.setPrice(price * (100 - discount) / 100);
			price = product.getPrice();
			std::cout << "New product price: " << price << "\n";
		}
		std::cout << "Your balance of GermanCoin: " << GERcoins.totalBalance() << "\n";
		if (GERcoins.totalBalance() < price)
		{
			std::cout << "You can't afford this product!\n";
			return;
		}
		GERcoins.tryToBuy(price);
	}
}
