#include <iostream>
#include "Vector.h"
template <typename T>
struct SmartFunc
{
    T (*mapPtr) (T) = nullptr;
    bool(*filterPtr)(T) = nullptr;
    T (*reducePtr) (Vector<T>) = nullptr;
    void setMap(T function(T));
    void useMap(Vector<T>& vector);
    void setFilter(bool function(T));
    void useFilter(Vector<T>& vector);
    void setReduce(T function(Vector<T>));
    void useReduce(Vector<T>& vector);
    void useMapWithReduce(Vector<T>& vector);
    void useFilterWithMap(Vector<T>& vector);
    void useFilterWithReduce(Vector<T>& vector);
};

template<typename T>
T addOne(T x)
{
   return x + 1;
}

template<typename T>
bool isEven(T element) {
    return element % 2 == 0;
}

template<typename T>
T sum(Vector<T> vector)
{
    T sum = 0;
    for (size_t i = 0; i < vector.getSize() ;++i)
    {
        sum += vector[i];
    }
    return sum;
}

template<typename T>
T product(Vector<T> vector)
{
    T product = 1;
    for (size_t i = 0; i < vector.getSize(); ++i)
    {
        product *= vector[i];
    }
    return product;
}

int main()
{
    Vector<int> vector;
    vector.pushBack(1);
    vector.pushBack(2);
    vector.pushBack(3);
    vector.pushBack(4);
    vector.pushBack(5);
    vector.pushBack(6);
    vector.pushBack(7);
    vector.pushBack(8);
    vector.pushBack(9);
    vector.print();
    SmartFunc<int> func;
    func.setMap(addOne);
    func.setFilter(isEven);
    func.setReduce(sum);
    func.useFilterWithReduce(vector);
    vector.print();
    return 0;
}



template<typename T>
void SmartFunc<T>::setFilter(bool function(T))
{
    this->filterPtr = function;
}

template<typename T>
void SmartFunc<T>::setMap(T function(T))
{
    this->mapPtr = function;
}

template<typename T>
void SmartFunc<T>::useMap(Vector<T>& vector)
{
    if (mapPtr == nullptr)
    {
        std::cout << "nullptr\n";
        return;
    }
    for (size_t i = 0; i < vector.getSize(); ++i)
    {
        vector[i] = mapPtr(vector[i]);
    }
}

template<typename T>
void SmartFunc<T>::useFilter(Vector<T>& vector)
{
    if (filterPtr == nullptr)
    {
        std::cout << "nullptr\n";
        return;
    }
    for (size_t i = 0; i < vector.getSize(); ++i)
    {
        if (filterPtr(vector[i]) == false)
        {
            vector.removeAt(i);
            i--;
        }
    }
}

template<typename T>
void SmartFunc<T>::setReduce(T function(Vector<T>))
{
    this->reducePtr = function;
}

template<typename T>
void SmartFunc<T>::useReduce(Vector<T>& vector)
{
    if (reducePtr == nullptr)
    {
        std::cout << "nullptr\n";
        return;
    }
    std::cout << reducePtr(vector) << "\n"; 
}

template<typename T>
void SmartFunc<T>::useMapWithReduce(Vector<T>& vector)
{
    if (mapPtr == nullptr || reducePtr == nullptr)
    {
        std::cout << "nullptr\n";
        return;
    }
    this->useMap(vector);
    this->useReduce(vector);
}

template<typename T>
void SmartFunc<T>::useFilterWithMap(Vector<T>& vector)
{
    if (filterPtr == nullptr || mapPtr == nullptr)
    {
        std::cout << "nullptr\n";
        return;
    }
    this->useFilter(vector);
    this->useMap(vector);
}

template<typename T>
void SmartFunc<T>::useFilterWithReduce(Vector<T>& vector)
{
    if (filterPtr == nullptr || reducePtr == nullptr)
    {
        std::cout << "nullptr\n";
        return;
    }
    this->useFilter(vector);
    this->useReduce(vector);
}
