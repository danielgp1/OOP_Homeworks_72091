#include "Rational.h"

Rational::Rational()
{
	this->numerator = 0;
	this->denominator = 1;
}

Rational::Rational(int num, int denom)
{
	this->numerator = num;
	this->denominator = denom;
}

void Rational::setNumerator(int _numerator)
{
	this->numerator = _numerator;
}

void Rational::setDenominator(int _denominator)
{
	if (_denominator == 0)
	{
		std::cout << "Denominator can't be 0!" << std::endl;
		return;
	}
	this->denominator = _denominator;
}

int Rational::getNumerator() const
{
	return this->numerator;
}

int Rational::getDenominator() const
{
	return this->denominator;
}

void Rational::printNumber() const
{
	std::cout << this->numerator << "/" << this->denominator << std::endl;
}

double Rational::operator+(Rational& _number)
{
	return this->calculate() + _number.calculate();
}

double Rational::operator-(Rational& _number)
{
	return this->calculate() - _number.calculate();;
}

double Rational::operator*(Rational& _number)
{
	return this->calculate() * _number.calculate();
}

double Rational::operator/(Rational& _number)
{
	return this->calculate() / _number.calculate();
}


bool Rational::operator==(Rational& _number)
{
	return this->calculate() == _number.calculate();
}

bool Rational::operator!=(Rational& _number)
{
	return this->calculate() != _number.calculate();
}

bool Rational::operator>=(Rational& _number)
{
	return this->calculate() >= _number.calculate();
}

bool Rational::operator<=(Rational& _number)
{
	return this->calculate() <= _number.calculate();
}

Rational& Rational::operator=(Rational& _number)
{
	this->numerator = _number.numerator;
	this->denominator = _number.denominator;
	return *this;
}

Rational& Rational::operator+=(Rational& _number)
{
	this->numerator *= _number.denominator;
	_number.numerator *= this->denominator;
	this->denominator *= _number.denominator;
	this->numerator += _number.numerator;
	return *this;
}

Rational& Rational::operator-=(Rational& _number)
{
	this->numerator *= _number.denominator;
	_number.numerator *= this->denominator;
	this->denominator *= _number.denominator;
	this->numerator -= _number.numerator;
	return *this;
}

Rational& Rational::operator*=(Rational& _number)
{
	this->numerator *= _number.numerator;
	this->denominator *= _number.denominator;
	return *this;
}

Rational& Rational::operator/=(Rational& _number)
{
	this->numerator *= _number.denominator;
	this->denominator *= _number.numerator;
	return *this;
}

double Rational::calculate()
{
	return this->numerator / this->denominator;
}
