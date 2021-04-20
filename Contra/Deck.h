#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>

template <typename T>
class Deck
{
public:
    Deck();
    void addCard(T newElement);
    void removeLast();
    void printCards() const;
    T drawCard();
    void shuffle();
    Deck<T> operator+(const T&);
    Deck<T>& operator+=(const T&);
    Deck<T>& operator=(const Deck<T>&);
    T& operator[](int);
private:
    T* deck;
    size_t size;
    size_t capacity;
    bool nameIsNotSame(T newElement);
    void removeFirstCard();
};


template <typename T>
T& Deck<T>::operator[](int i)
{
    return deck[i];
}

template <typename T>
Deck<T>& Deck<T>::operator+=(const T& _card)
{
    *this = *this + _card;
    return *this;
}


template <typename T>
Deck<T> Deck<T>::operator+(const T& _card)
{
    Deck temp = *this;
    temp.addCard(_card);
    return temp;
}

template <typename T>
Deck<T>& Deck<T>::operator=(const Deck& _deck)
{
    if (this != &_deck)
    {
        this->size = _deck.size;
        this->capacity = _deck.capacity;
        for (size_t i = 0; i < this->size; ++i)
        {
            this->deck[i] = _deck.deck[i];
        }   
    }
    return *this;
}

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void Deck<T>::shuffle()
{   
    srand(time(NULL));
    for (size_t i = this->size - 1; i > 0; i--)
    {
        int j = rand() % (i+1);
        swap(deck[i], deck[j]);
    }
}

template<typename T>
void Deck<T>::removeFirstCard()
{
    for (size_t i = 0; i < size-1; i++)
    {
        deck[i] = deck[i + 1];
    }
    size--;
}

template<typename T>
T Deck<T>::drawCard()
{
    T temp = deck[0];
    this->removeFirstCard();
    this->addCard(temp);
    return temp;
}


template<typename T>
bool Deck<T>::nameIsNotSame(T newElement) 
{
    for (size_t i = 0; i < size; ++i)
    {
        if (deck[i] == newElement)
            return false;
    }
    return true;
}


template <typename T>
Deck<T>::Deck() {
    size = 0;
    capacity = 30;
    deck = new T[capacity];
}


template <typename T>
void Deck<T>::addCard(T newElement)
{  
    if (size != capacity)
    {
        if(nameIsNotSame(newElement))
        {
            deck[size++] = newElement;
        }
        else
        {
            std::cout << "The card \"" << newElement.getName() << "\" is already in the deck!\n";
        }
    }
    else
    {
        std::cout << "The deck is full!\n";
    }
}

template <typename T>
void Deck<T>::removeLast()
{
    if (size > 0)
    {
        this->size--;
    }
}

template <typename T>
void Deck<T>::printCards() const
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << this->deck[i] << std::endl;
    }
}

