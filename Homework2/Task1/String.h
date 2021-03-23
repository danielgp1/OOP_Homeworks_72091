#pragma once
#include <cstring>
#include <iostream>
class String
{
public:
	String();
	//String(const char* _charArray, int _size, int _capacity);
	~String();
	String(const String& _string);
	String& operator=(String _string);
	void printData() const;
	void setCharArray(const char* _charArray);
	void setSizeAndCapacity(int _size,int _capacity);
	const char* getCharArray() const;
	int getSize() const;
	int getCapacity() const;
	void resize();
	void add(char newElement);
	int getLength() const;
	void insertAt(int index,char newElement);
	void removeAt(int index);
	void trimStart();
	void trimEnd();
	void trimStart(int number);
	void trimEnd(int number);
	String operator+(String& _string);
	String& operator+=(String& _string);
	bool operator==(String& _string);
	bool operator!=(String& _string);
	char operator[](int index);
private:
	char* charArray;
	int size;
	int capacity;
	void copy(const String& _string);
	void erase();
	void checkCapacity();
};

