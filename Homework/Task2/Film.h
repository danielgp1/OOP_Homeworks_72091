#pragma once

class Film
{
public:
	void copy(const Film& _film);
	void erase();
	Film();
	Film(const char* _filmName, const char* _directorName, int _countOfAwards);
	void setFilmName(const char* _filmName);
	void setDirectorName(const char* _directorName);
	void setCountOfAwards(int _countOfAwards);
	const char* getFilmName() const;
	const char* getDirectorName() const;
	int getCountOfAwards() const;
	void printInfo() const;
	~Film();
	Film& operator=(const Film& _film);
	Film(const Film& _film);

private:
	char* filmName;
	char* directorName;
	int countOfAwards;
};