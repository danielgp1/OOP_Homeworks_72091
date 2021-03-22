#pragma once
#include <iostream>
class Rational
{
public:
	Rational();
	Rational(int num, int denom);
	void setNumerator(int _numerator);
	void setDenominator(int _denominator);
	int getNumerator() const;
	int getDenominator() const;
	void printNumber() const;
	double operator+(Rational& _number);
	double operator-(Rational& _number);
	double operator*(Rational& _number);
	double operator/(Rational& _number);
	bool operator==(Rational& _number);
	bool operator!=(Rational& _number);
	bool operator>=(Rational& _number);
	bool operator<=(Rational& _number);
	Rational& operator=(Rational& _number);
	Rational& operator+=(Rational& _number);
	Rational& operator-=(Rational& _number);
	Rational& operator*=(Rational& _number);
	Rational& operator/=(Rational& _number);
private:
	int numerator;
	int denominator;
	double calculate();
};

