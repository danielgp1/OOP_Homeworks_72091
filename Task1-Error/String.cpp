#include "String.h"

void String::resize()
{
	this->capacity *= 2;
	char* newCharArray = new char[capacity];
	strcpy_s(newCharArray, this->size, this->charArray);
	delete[] this->charArray;
	this->charArray = newCharArray;
}

void String::add(char newElement)
{
	this->checkCapacity();
	this->charArray[size] = '\0';
	this->charArray[size - 1] = newElement;
	this->size++;
}

int String::getLength() const
{
	return this->size-1;
}

void String::insertAt(int index,char newElement)
{
	if (index >= this->size)
		return;
	this->checkCapacity();
	for (int i = size + 1; i > index; i--)
	{
		this->charArray[i] = this->charArray[i - 1];
	}
	this->charArray[index] = newElement;
	this->size++;
}

void String::removeAt(int index)
{
	if (index >= this->size)
		return;
	for (int i = index; i <size ; i++)
	{
		this->charArray[i] = this->charArray[i + 1];
	}
	this->size--;
}

void String::trimStart()
{
	if (this->size > 1)
	{
		for (int i = 0; i < size; i++)
		{
			this->charArray[i] = this->charArray[i + 1];
		}
		this->size--;
	}
}

void String::trimEnd()
{
	if (this->size > 1)
	{
		this->size--;
		this->charArray[size-1] = '\0';
	}
}

void String::trimStart(int number)
{
	for (int i = 0; i < number; i++)
	{
		this->trimStart();
	}
}

void String::trimEnd(int number)
{
	for (int i = 0; i < number; i++)
	{
		this->trimEnd();
	}
}

String& String::operator+(String& _string)
{
	String helper;
	helper = *this;
	for (int i = 0; i < _string.size-1; i++)
	{
		helper.add(_string.charArray[i]);
	}
	return helper;
}

String& String::operator+=(String& _string)
{
	*this = *this + _string;
	return  *this;
}

bool String::operator==(String& _string)
{
	if (this->size != _string.size)
	{
		return false;
	}
	for (int i = 0; i < this->size; i++)
	{
		if (this->charArray[i] != _string.charArray[i])
			return false;
	}
	return true;
}

bool String::operator!=(String& _string)
{
	if (this->size != _string.size)
	{
		return true;
	}
	for (int i = 0; i < this->size; i++)
	{
		if (this->charArray[i] != _string.charArray[i])
			return true;
	}
	return false;
}

char String::operator[](int index)
{
	if (index > this->size )
		return '\0';
	return this->charArray[index-1];
}

void String::copy(String& _string)
{
	this->capacity = _string.capacity;
	this->size = _string.size;
	this->charArray = new char[_string.capacity];
	strcpy_s(this->charArray, _string.size, _string.charArray);
}

void String::erase()
{
	delete[] this->charArray;
}

void String::checkCapacity()
{
	if (this->size + 1 > this->capacity)
	{
		this->resize();
	}
}

String::String()
{
	this->size = 1;
	this->capacity = 10;
	this->charArray = new char[capacity];
	charArray[0] = '\0';
}

String::~String()
{
	this->erase();
}

String& String::operator=(String& _string)
{
	if (this != &_string)
	{
		this->erase();
		this->copy(_string);
	}
	return *this;
}

void String::printData() const
{
	std::cout << this->charArray << std::endl;
	std::cout << this->capacity << std::endl;
	std::cout << this->size << std::endl;
}

void String::setCharArray(const char* _charArray)
{
	delete[] this->charArray;
	this->charArray = new char[strlen(_charArray) + 1];
	strcpy_s(this->charArray, strlen(_charArray) + 1, _charArray);
}

void String::setSizeAndCapacity(int _size, int _capacity)
{
	if (_size > _capacity)
		return;
	this->size = _size;
	this->capacity = _capacity;
}

const char* String::getCharArray() const
{
	return this->charArray;
}

int String::getSize() const
{
	return this->size;
}

int String::getCapacity() const
{
	return this->capacity;
}

