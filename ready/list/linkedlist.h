#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include "linearlist.h"

using namespace std;

template <class T>
class LinkedList : public LinearList<T>
{
protected:
    T *next;
    size_t length;

public:
    LinkedList();
    ~LinkedList();
    size_t size() const;
    void push_back(const T &value);
};

// ------impl------

template <class T>
LinkedList<T>::LinkedList()
{
    cout << "construct" << endl;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    cout << "destory" << endl;
}

template <class T>
size_t LinkedList<T>::size() const
{
    return length;
}

template <class T>
void LinkedList<T>::push_back(const T &value)
{

}

#endif // LINKEDLIST_H_
