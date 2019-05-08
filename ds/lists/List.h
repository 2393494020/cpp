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

        Node( const T & newData = T {}, Node * p = nullptr, Node * n = nullptr ) : data { newData }, prev { p }, next { n }
        {

        }

        Node( T && newData, Node * p = nullptr, Node * n = nullptr ) : data { std::move(newData) }, prev { p }, next { n }
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

    explicit List<T>()
    {
        std::cout << "init" << std::endl;
        init();
    }

    List( const List<T> & rhs );

    List<T> & operator= ( const List<T> & rhs );

    List( List<T> && rhs );

    List<T> & operator= ( List<T> && rhs );

    ~List<T>()
    {
        clear();
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

    void push_back( const T & ele )
    {
        Node *current = new Node(ele, tail->prev, tail);
        
        tail->prev->next = current;
        tail->prev = current;

        ++theSize;
    }

    void push_back( const T && ele )
    {
        Node *current = new Node(ele, tail->prev, tail);
        
        tail->prev->next = current;
        tail->prev = current;

        ++theSize;
    }

    void pop_back();

    const T & back();

    const T & front();

    void push_front(const T & ele);

    void pop_front();

    const T & operator[]( int index ) const
    {
        Node *p = head;
        for (int i = 0; i <= index; ++i)
        {
            p = p->next;
        }

        return p->data;
        
    }

    T & operator[]( int index )
    {
        Node *p = head;
        for (int i = 0; i <= index; ++i)
        {
            p = p->next;
        }

        return p->data;
        
    }

    void print() const
    {
        Node *p = head;
        for (int i = 0; i < theSize; ++i)
        {
            p = p->next;
            std::cout << p->data << std::endl;
        }        
    }
    
    void insert(int pos, const T & ele)
    {
        Node *p = head;
        for (int i = 0; i <= pos; ++i)
        {
            p = p->next;
        }

        Node *current = new Node(ele, p->prev, p);
        p->prev->next = current;

        ++theSize;
    }

    iterator erase(iterator pos);

    iterator erase(iterator start, iterator end);

private:
    // Keep track of the size in a data member so that the size method can be implemented in constant time.
    int theSize;
    Node *head;
    Node *tail;

    void init()
    {
        theSize = 0;
        head = new Node;
        tail = new Node;

        head->next = tail;
        tail->prev = head;
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


#endif //DS_LIST_H
