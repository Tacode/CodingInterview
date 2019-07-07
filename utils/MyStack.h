#pragma once
#include <iostream>
#include <stack>
#define EmptyTOS -1
using namespace std;

template <typename T>
class MyStack{
public:
    MyStack(int cap);
    virtual ~MyStack();
    virtual void push(const T& value);
    virtual void pop();
    T top() const;
    bool empty() const;
    size_t size() const;
protected:
    T *array;
    int counts;
    int capacity;
};

template<typename T>
MyStack<T>::MyStack(int cap)
{
    array = new T[cap];
    counts = EmptyTOS;
    capacity = cap;
}

template<typename T>
MyStack<T>::~MyStack()
{
    delete []array;
}

template<typename T>
void MyStack<T>::push(const T &value)
{
    array[++counts] = value;
}

template<typename T>
void MyStack<T>::pop()
{
    if (empty())
        cerr << "Empty Stack" << endl;
    counts--;
}

template<typename T>
T MyStack<T>::top() const
{
    if (!empty())
        return array[counts];
    else{
        cerr << "Empth Stack" << endl;
        return 0;
    }

}

template<typename T>
bool MyStack<T>::empty() const
{
    return counts == EmptyTOS;
}

template<typename T>
size_t MyStack<T>::size() const
{
    return counts+1;
}
