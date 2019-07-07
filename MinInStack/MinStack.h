#ifndef MINSTACK_H
#define MINSTACK_H
#include "MyStack.h"
#include <iostream>
#include <assert.h>
using namespace std;

template <typename T>
class MinStack:public MyStack<T>{
public:
    MinStack(int cap):MyStack<T>(cap){}
    virtual void push(const T& value);
    virtual void pop();
    T min_value() const;
protected:
    MyStack<T> *m_stack = new MyStack<T>(MyStack<T>::capacity);
};

#endif // MINSTACK_H

template<typename T>
void MinStack<T>::push(const T &value)
{
    this->array[++this->counts] = value;
    if (m_stack->empty() || value < m_stack->top())
        m_stack->push(value);
    else
        m_stack->push(m_stack->top());
}

template<typename T>
void MinStack<T>::pop()
{
    assert(!this->empty() && !m_stack->empty());
    this->counts--;
    m_stack->pop();
}

template<typename T>
T MinStack<T>::min_value() const
{
    assert(!this->empty() && !m_stack->empty());
    return m_stack->top();
}
