//
// Created by juno on 19-3-28.
// 双向链表
//

#ifndef DS_LISTS_LIST_H
#define DS_LISTS_LIST_H

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

            const_iterator & operator-- ()
            {
                current = current->prev;
                return *this;
            }

            const_iterator operator-- ( int )
            {
                const_iterator old = *this;
                --( *this );
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

            const_iterator( Node * p ) : current { p }
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

            const T & operator* () const
            {
                return const_iterator::operator*();
            }

            // prefix
            // ++itr
            iterator & operator++ ()
            {
                this->current = this->current->next;
                return *this;
            }

            // postfix
            // itr++
            iterator operator++ ( int )
            {
                iterator old = *this;
                ++( *this );
                return old;
            }

            iterator & operator-- ()
            {
                this->current = this->current->prev;
                return *this;
            }

            iterator operator-- ( int )
            {
                iterator old = *this;
                --( *this );
                return old;
            }

        protected:
            iterator( Node *p ) : const_iterator{ p }
            {}

            // It grants to the List<T> class access to const_iterator's nonpublic members.
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

    iterator begin()
    {
        return { head->next };
    }

    const_iterator begin() const
    {
        return { head->next };
    }

    iterator end()
    {
        return { tail };
    }

    const_iterator end() const
    {
        return { tail };
    }

    void clear()
    {
        while ( !empty() )
        {
            pop_front();
        }        
    }

    int size() const
    {
        return theSize;
    }

    bool empty() const
    {
        return size() == 0;
    }

    void push_back( const T & x )
    {
        insert( end(), x );
    }

    void push_back( const T && x )
    {
        insert( end(), std::move( x ) );
    }

    void pop_back()
    {
        erase( --( end() ) );
    }

    const T & back()
    {
        *( --( end() ) );
    }

    const T & front()
    {
        *( begin() );
    }

    void push_front(const T & x)
    {
        insert( begin(), x );
    }

    void push_front(const T && x)
    {
        insert( begin(), std::move( x ) );
    }

    void pop_front()
    {
        erase( begin() );
    }

    void print() const
    {
        for ( auto itr = begin(); itr != end(); ++itr )
        {
            std::cout << *itr << std::endl;
        }
    }
    
    iterator insert( iterator itr, const T & x )
    {
        Node *p = itr.current;
        Node *newNode = new Node{ x, p->prev, p };
        p->prev->next = newNode;
        p->prev = newNode;
        ++theSize;

        return { newNode };
    }

    iterator insert( iterator itr, const T && x )
    {
        Node *p = itr.current;
        Node *newNode = new Node{ std::move( x ), p->prev, p };
        p->prev->next = newNode;
        p->prev = newNode;
        ++theSize;

        return { newNode };
    }

    iterator erase( iterator pos )
    {
        
        Node *p = pos.current;
        p->prev->next = p->next;
        p->next->prev = p->prev;

        iterator itr = { p->next };

        delete p;
        --theSize;

        return itr;
    }

    iterator erase( iterator start, iterator end );

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
