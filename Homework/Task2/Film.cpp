#include <iostream>
#include "Film.h"
#include <cstring>

void Film::copy(const Film& _film)
{
	this->filmName = new char[strlen(_film.filmName) + 1];
	strcpy_s(this->filmName, strlen(_film.filmName) + 1, _film.filmName);
	this->directorName = new char[strlen(_film.directorName) + 1];
	strcpy_s(this->directorName, strlen(_film.directorName) + 1, _film.directorName);
	this->countOfAwards = _film.countOfAwards;
}

void Film::erase()
{
	delete[] this->filmName;
	delete[] this->directorName;
}

Film::Film()
{
	this->filmName = new char[5];
	strcpy_s(this->filmName, 5, "none");
	this->directorName = new char[5];
	strcpy_s(this->directorName, 5, "none");
	this->countOfAwards = 0;
}

Film::Film(const char* _filmName, const char* _directorName, int _countOfAwards)
{
	this->filmName = new char[strlen(_filmName) + 1];
	strcpy_s(this->filmName, strlen(_filmName) + 1, _filmName);
	this->directorName = new char[strlen(_directorName) + 1];
	strcpy_s(this->directorName, strlen(_directorName) + 1, _directorName);
	this->countOfAwards = _countOfAwards;
}

void Film::setFilmName(const char* _filmName)
{
	delete[] this->filmName;
	this->filmName = new char[strlen(_filmName) + 1];
	strcpy_s(this->filmName, strlen(_filmName) + 1, _filmName);
}

void Film::setDirectorName(const char* _directorName)
{
	delete[] this->directorName;
	this->directorName = new char[strlen(_directorName) + 1];
	strcpy_s(this->directorName, strlen(_directorName) + 1, _directorName);
}

void Film::setCountOfAwards(int _countOfAwards)
{
	this->countOfAwards = _countOfAwards;
}

const char* Film::getFilmName() const
{
	return this->filmName;
}

const char* Film::getDirectorName() const
{
	return this->directorName;
}

int Film::getCountOfAwards() const
{
	return this->countOfAwards;
}

void Film::printInfo() const
{
	std::cout << this->filmName << std::endl;
	std::cout << this->directorName << std::endl;
	std::cout << this->countOfAwards << std::endl;
}

Film::~Film()
{
	this->erase();
}

Film& Film::operator=(const Film& _film)
{
	if (this != &_film)
	{
		this->erase();
		this->copy(_film);
	}
	return *this;
}

Film::Film(const Film& _film)
{
	this->copy(_film);
}