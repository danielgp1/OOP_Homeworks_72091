#pragma once
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <time.h>
class Coin
{
public:
	virtual void flip();
	void evaluate();
	void print() const;
	~Coin();
	Coin(const Coin&);
	Coin& operator=(const Coin&);
	Coin();
	Coin(size_t);
	size_t getValue() const;
	size_t getSide() const;
protected:
	enum side { HEADS, TAILS };
	side _side;
	char* nationality;
	size_t value;
	void copy(const Coin&);
	void erase();
};

