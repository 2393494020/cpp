//
// Created by juno on 19-3-28.
//

#ifndef DS_VECTOR_H
#define DS_VECTOR_H

#include <algorithm>

#include "Container.h"

template<typename T>
class Vector : public Container<T> {
public:
    explicit Vector(int initSize = 0);

    Vector( const Vector & rhs );

    Vector( Vector && rhs );

    ~Vector() {
        delete [] objects;
    }

    Vector & operator= ( const Vector & rhs );

    Vector & operator= ( Vector && rhs );

    int size() const
    {
        return theSize;
    }

    bool empty() const
    {
        return size() == 0;
    }

    void clear();

    const T & back() const {
        return objects[ theSize - 1];
    }

    void pop_back()
    {
        --theSize;
    }

    void push_back( const T & ele )
    {
        if ( theSize == theCapacity  )
            reserve( 2 * theCapacity + 1 );

        objects[ theSize++ ] = ele;
        std::cout << "lvalue " << theSize << std::endl;
    }

    void push_back( T && ele )
    {
        if ( theSize == theCapacity  )
            reserve( 2 * theCapacity + 1 );

        objects[ theSize++ ] = std::move( ele );
        std::cout << "rvalue " << ele << std::endl;
    }


    T & operator[]( int index )
    {
        return objects[ index ];
    }

    const T & operator[]( int index ) const
    {
        return objects[ index ];
    }

    void reserve(int newCapacity);

    void resize(int newSize);

    typedef T * iterator;
    typedef const T * const_iterator;

    iterator begin()
    {
        return &objects[ 0 ];
    }

    const_iterator begin() const
    {
        return &objects[ 0 ];
    }

    iterator end()
    {
        return &objects[ size() ];
    }

    const_iterator end() const
    {
        return &objects[ size() ];
    }

    iterator insert(iterator pos, const T & ele);

    iterator erase(iterator pos);

    iterator erase(iterator start, iterator end);

    int capacity() const
    {
        return theCapacity;
    }

    static const int SPARE_CAPACITY = 16;

private:
    int theSize;
    int theCapacity;
    T * objects;
};

template<class T>
Vector<T>::Vector(int initSize) : theSize{ initSize }, theCapacity{ initSize + SPARE_CAPACITY }
{
    objects = new T[ theCapacity ];
}

/**
 * copy constructor
 **/
template<class T>
Vector<T>::Vector( const Vector & rhs ) : theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ nullptr }
{
    objects = new T[ theCapacity ];
    for ( int i = 0; i < theSize; ++i )
    {
        objects[i] = rhs.objects[i];
    }
}

/**
 * move constructor
 **/
template<class T>
Vector<T>::Vector( Vector && rhs ) : theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ rhs.objects }
{
    rhs.theSize = 0;
    rhs.theCapacity = 0;
    rhs.objects = nullptr;
}

/**
 * copy assignment operator=
 **/
template<class T>
Vector<T> & Vector<T>::operator= ( const Vector & rhs )
{
    Vector copy = rhs;
    std::swap( *this, copy );
    return *this;
}

/**
 * move assignment operator=
 **/
template<class T>
Vector<T> & Vector<T>::operator= ( Vector && rhs )
{
    std::swap( theSize, rhs.theSize );
    std::swap( theCapacity, rhs.theCapacity );
    std::swap( objects, rhs.objects );

    return *this;
}

template<class T>
void Vector<T>::resize( int newSize )
{
    if ( newSize > theCapacity )
        reserve( newSize * 2 );
    
    theSize = newSize;
}

/**
 * The capacity is changed by obtaining a new block of memory for the primitive array,
 * copying the old block into the new block, and reclaiming the old block.
 **/
template<class T>
void Vector<T>::reserve( int newCapacity )
{
    if ( newCapacity < theSize )
        return;
    
    T *newArray = new T[ newCapacity ];
    for( int i = 0; i < theSize; i++ )
    {
        newArray[ i ] = std::move( objects[ i ] );
    }
    
    theCapacity = newCapacity;
    std::swap( objects, newArray );
    delete [] newArray;
}

template<class T>
void Vector<T>::clear()
{
    std::cout << "vector clear" << std::endl;
}

#endif //DS_VECTOR_H
