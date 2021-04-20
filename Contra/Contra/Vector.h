#pragma once
#include <iostream>
template <typename T>
class Vector
{
public:
    Vector();
    Vector(const Vector& other);
    Vector& operator= (const Vector& other);
    ~Vector();
    void add(T newElement);
    void removeLast();
    void printCards() const;
private:
    T* vector;
    size_t size;
    size_t capacity;
    void erase();
    void copy(const Vector& other);
    void resize();
};


template <typename T>
Vector<T>::Vector() {
    size = 0;
    capacity = 8;
    vector = new T[capacity];
}

template <typename T>
Vector<T>::Vector(const Vector& other)
{
    this->copy(other);
}

template <typename T>
void Vector<T>::resize() {
    this->capacity *= 2;
    T* newVector = new T[this->capacity];

    for (size_t i = 0; i < size; i++)
    {
        newVector[i] = this->vector[i];
    }

    delete[] vector;
    this->vector = newVector;
}


template <typename T>
void Vector<T>::erase()
{
    delete[] this->vector;
}

template <typename T>
void Vector<T>::copy(const Vector& other) {
    this->vector = new T[other.capacity];
    this->size = other.size;
    this->capacity = other.capacity;

    for (size_t i = 0; i < size; i++)
    {
        this->vector[i] = other.vector[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
    if (this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    this->erase();
}

template <typename T>
void Vector<T>::add(T newElement)
{
    if (size >= capacity)
    {
        this->resize();
    }
    this->vector[size++] = newElement;
}

template <typename T>
void Vector<T>::removeLast()
{
    if (size > 0)
    {
        this->size--;
    }
}

template <typename T>
void Vector<T>::printCards() const
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << this->vector[i] << std::endl;
    }
}

