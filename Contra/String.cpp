#include "String.h"

String::String()
{
	capacity = 1;
	size = 0;
	text = new char[capacity];
	text[0] = '\0';
}

String::String(const char* _string)
{
	this->capacity = strlen(_string) + 1;
	this->text = new char[capacity];
	strcpy_s(this->text, capacity, _string);
	this->size = strlen(_string);
}

String::~String()
{
	this->erase();
}

String::String(const String& _string)
{
	this->copy(_string);
}

String& String::operator=(const String& _string)
{
	if (this != &_string)
	{
		this->erase();
		this->copy(_string);
	}
	return *this;
}

bool String::operator==(const String& _string)
{
	return !strcmp(this->text,_string.text);
}

void String::print() const
{
	std::cout << this->text << std::endl;
	std::cout << this->capacity << std::endl;
	std::cout << this->size << std::endl;
}


void String::copy(const String& _string)
{
	this->capacity = _string.capacity;
	this->size = _string.size;
	this->text = new char[this->capacity];
	strcpy_s(this->text, this->capacity, _string.text);
}

void String::erase()
{
	delete[] this->text;
}

std::ostream& operator<<(std::ostream& out, const String& _string)
{
	out << _string.text;
	return out;
}

std::istream& operator>>(std::istream& in, const String& _string)
{
	in >> _string.text;
	return in;
}
