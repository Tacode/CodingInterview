#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <iostream>
using namespace std;
template <typename T>
class MyQueue{
public:
    MyQueue(int cap);
    virtual ~MyQueue();
    bool empty() const;
    bool full() const;
    virtual void push(const T value);
    virtual void pop();
    virtual void makeEmpty();
    T front() const;
    void traverse() const;
    int size() const;


protected:
    T *array;
    int first;
    int last;
    int capacity;
    int sizes;

};

#endif // MYQUEUE_H

template<typename T>
MyQueue<T>::MyQueue(int cap)
{
    array = new T[cap];
    capacity = cap;
    first = last = -1;
    sizes = 0;
}

template<typename T>
MyQueue<T>::~MyQueue()
{
    delete []array;
}

template<typename T>
bool MyQueue<T>::empty() const
{
    return first == -1;
}

template<typename T>
bool MyQueue<T>::full() const
{
    return first==0 && last == last-1 && last == first-1;
}

template<typename T>
void MyQueue<T>::push(const T value)
{
    if (!full()){
        if (last==-1 || last==capacity-1){
            array[0] = value;
            last = 0;
            if (first == -1)
                first = 0;
        }
        else
            array[++last] = value;
        sizes++;
    }
    else{
        cout << "Queue Full" << endl;
        exit(0);
    }
}

template<typename T>
void MyQueue<T>::pop()
{
    if (empty()){
        cout << "Queue empty" << endl;
        exit(0);
    }
    if (first == last)
        last = first = -1;
    else if(first == capacity-1)
        first = 0;
    else
        first++;
    sizes--;
}

template<typename T>
void MyQueue<T>::makeEmpty()
{
    first = -1;
    last = -1;
    sizes = 0;

}

template<typename T>
T MyQueue<T>::front() const
{
    if (empty()){
        cout << "Queue empty" << endl;
        exit(0);
    }
    return array[first];
}

template<typename T>
void MyQueue<T>::traverse() const
{
    if (empty()){
        cout << "Queue empty" << endl;
        return;
    }
    if (last > first){
        for (int i=first; i<=last; ++i)
            cout << array[i] << " ";
        cout << endl;
    }
    else
    {
        for (int i=first; i<=capacity-1; ++i)
            cout << array[i] << " ";
        for (int i=0; i<=last; ++i)
            cout << array[i] << " ";
        cout << endl;
    }
}

template<typename T>
int MyQueue<T>::size() const
{
    return sizes;
}
