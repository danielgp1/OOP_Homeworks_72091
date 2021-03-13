#pragma once
#include "Film.h"
class FilmRanking
{
public:
	void swap(Film& _film, Film& _film2);
	void sortByAwards();
	void erase();
	void copy(const FilmRanking& _otherRanking);
	FilmRanking();
	FilmRanking(const Film* _films, int _size);
	FilmRanking& operator=(const FilmRanking& _otherRanking);
	FilmRanking(const FilmRanking& _otherRanking);
	~FilmRanking();
	void setFilmRanking(const Film* _films,int _size);
	int getSize() const;
	const Film* getFilmList() const;
	void TopFilms(int n);

private:
	Film* films;
	int size;
};