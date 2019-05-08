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
        {}

        Node( T && newData, Node * p = nullptr, Node * n = nullptr ) : data { std::move(newData) }, prev { p }, next { n }
        {}
    };


public:
    class const_iterator
    {
        public:
            const_iterator() : current { nullptr }
            {}

            const T & operator* () const
            {
                return retrieve();
            }

            const_iterator & operator++ ()
            {
                current = current->next;
                return *this;
            }

            const_iterator operator++ ( int )
            {
                const_iterator old = *this;
                ++( *this );
                return old;
            }

            bool operator== ( const const_iterator & rhs ) const
            {
                return current == rhs.current;
            }

            bool operator!= ( const const_iterator & rhs ) const
            {
                return !( *this == rhs );
            }

        protected:
            Node *current;

            T & retrieve() const
            {
                return current->data;
            }

            const_iterator(Node * p) : current { p }
            {}

            friend class List<T>;
    };

    class iterator : public const_iterator
    {
        public:
            iterator()
            {}

            T & operator* ()
            {
                return const_iterator::retrieve();
            }

            const T & operator*() const
            {
                return const_iterator::operator*();
            }

            iterator & operator++ ()
            {
                this->current = this->current->next;
                return *this;
            }

            iterator operator++ ( int )
            {
                iterator old = *this;
                ++( *this );
                return old;
            }

        protected:
            iterator( Node *p ) : const_iterator{ p }
            {}

            friend class List<T>;
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
        delete head;
        delete tail;
    }

    void clear()
    {
        
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
        for ( int i = 0; i < theSize; ++i )
        {
            p = p->next;
            std::cout << p->data << std::endl;
        }        
    }
    
    void insert( int pos, const T & ele )
    {
        Node *p = head;
        for ( int i = 0; i <= pos; ++i )
        {
            p = p->next;
        }

        Node *newNode = new Node{ ele, p->prev, p };
        p->prev->next = newNode;
        p->prev = newNode;

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
    List<T>::init();

    for ( auto & ele : rhs )
        List<T>::push_back( ele );
}

// copy assignment
template<class T>
List<T> & List<T>::operator= ( const List<T> & rhs )
{
    List<T> copy = rhs;
    std::swap( *this, copy );
    return *this;
}

// move constructor
template<class T>
List<T>::List( List<T> && rhs ) : theSize { rhs.theSize }, head { rhs.head }, tail { rhs.tail }
{
    rhs.theSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
}

// copy assignment
template<class T>
List<T> & List<T>::operator= ( List<T> && rhs )
{
    std::swap( theSize, rhs.theSize );
    std::swap( head, rhs.head );
    std::swap( tail, rhs.tail );

    return *this;
}


#endif //DS_LIST_H
