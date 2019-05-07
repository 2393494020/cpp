//
// Created by juno on 19-3-28.
// 双向链表
//

#ifndef DS_LIST_H
#define DS_LIST_H

#include "Container.h"

template<class T>
class List : public Container<T> {
private:
    struct Node
    {
        T data;
        Node *prev;
        Node *next;

        Node(const T & newData = T {}, Node * p = nullptr, Node * n = nullptr) : data { newData }, prev { p }, next { n }
        {

        }

        Node(T && newData)
        {

        }
    };


public:
    class const_iterator
    {

    };

    class iterator : public const_iterator
    {

    };

    explicit List<T>(int initSize = 0) : theSize { initSize }
    {

    }

    List( const List<T> & rhs );

    List<T> & operator= ( const List<T> & rhs );

    List( List<T> && rhs );

    List<T> & operator= ( List<T> && rhs );

    ~List<T>()
    {

    }

    void clear() {

    }

    int size() const
    {
        return theSize;
    }

    bool empty() const
    {
        return size() == 0;
    }

    void push_back( const T & ele );

    void pop_back();

    const T & back();

    const T & front();

    void push_front(const T & ele);

    void pop_front();

    T & operator[] (int idx);

    T & at(int idx);
    
    iterator insert(iterator pos, const T & ele);

    iterator erase(iterator pos);

    iterator erase(iterator start, iterator end);

private:
    int theSize;
    Node *head;
    Node *tail;

    void init()
    {
        theSize = 0;
        head = new Node;
        tail = new Node;

        head->next = tail;
        tail->prev = tail;
    }

};


// copy constructor
template<class T>
List<T>::List( const List<T> & rhs )
{
    
}

// copy assignment
template<class T>
List<T> & List<T>::operator= ( const List<T> & rhs )
{

}

// move constructor
template<class T>
List<T>::List( List<T> && rhs )
{

}

// copy assignment
template<class T>
List<T> & List<T>::operator= ( List<T> && rhs )
{

}

template<class T>
void List<T>::push_back( const T & ele ) {

}

#endif //DS_LIST_H
