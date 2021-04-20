#pragma once
#include <cstring>
#include <iostream>
#include <cstring>
class String
{
public:
	String();
	String(const char*);
	~String();
	String(const String& _string);
	String& operator=(const String& _string);
	bool operator==(const String& _string);
	friend std::ostream& operator <<(std::ostream& out, const String& _string);
	void print() const;
private:
	size_t capacity;
	size_t size;
	char* text;
	void copy(const String& _string);
	void erase();
};

