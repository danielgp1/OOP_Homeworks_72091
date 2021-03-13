#include <iostream>
#include "FilmRanking.h"
Film demo("none", "none", 0);

void FilmRanking::swap(Film& _film, Film& _film2)
{
	Film help = _film;
	_film = _film2;
	_film2 = help;
}

void FilmRanking::sortByAwards()
{
	for (int i = 0; i < this->size; i++)
	{
		for (int j = i + 1; j < this->size; j++)
		{
			if (films[i].getCountOfAwards() < films[j].getCountOfAwards())
			{
				swap(films[i], films[j]);
			}
		}
	}
}
void FilmRanking::erase()
{
	delete[] this->films;
}

void FilmRanking::copy(const FilmRanking& _otherRanking)
{
	this->size = _otherRanking.size;
	for (int i = 0; i < size; i++)
	{
		this->films[i] = _otherRanking.films[i];
	}
}

FilmRanking::FilmRanking()
{
	this->size = 1;
	this->films = new Film[size];
	this->films[0] = demo;
}

FilmRanking::FilmRanking(const Film* _films, int _size)
{
	this->size = _size;
	this->films = new Film[size];
	for (int i = 0; i < size; i++)
	{
		this->films[i] = _films[i];
	}
}

FilmRanking& FilmRanking::operator=(const FilmRanking& _otherRanking)
{
	if (this != &_otherRanking)
	{
		this->erase();
		this->films = new Film[_otherRanking.size];
		this->copy(_otherRanking);
	}
	return *this;
}

FilmRanking::FilmRanking(const FilmRanking& _otherRanking)
{
	this->copy(_otherRanking);
}

FilmRanking::~FilmRanking()
{
	this->erase();
}

void FilmRanking::setFilmRanking(const Film* _films,int _size)
{
	this->size = _size;
	this->erase();
	this->films = new Film[size];
	for (int i = 0; i < this->size; i++)
	{
		this->films[i] = _films[i];
	}
}

int FilmRanking::getSize() const
{
	return this->size;
}

const Film* FilmRanking::getFilmList() const
{
	return this->films;
}

void FilmRanking::TopFilms(int n)
{
	if (n > this->size)
	{
		std::cout << "Error!" << std::endl;
		return;
	}
	this->sortByAwards();
	for (int i = 0; i < n; i++)
	{
		std::cout << "Number " << i + 1 << ": " << std::endl; 
		this->films[i].printInfo();
		std::cout << std::endl;
	}
}
