//
// Created by juno on 19-3-28.
//

#ifndef DS_VECTOR_H
#define DS_VECTOR_H

#include "Container.h"

template<typename T>
class Vector : public Container<T> {
public:
    explicit Vector(int initSize = 0);

    Vector(const Vector &rhs);

    Vector(const Vector &&rhs);

    ~Vector() {
        delete[] objects;
    }

    int size() const
    {
        return theSize;
    }

    bool empty() const
    {
        return size() == 0;
    }

    void clear();

    const T & back();

    void pop_back();

    void push_back(const T & ele);

    const T & front();

    T & operator[] (int idx);

    T & at(int idx);

    void reserve(int newCapacity);

    iterator insert(iterator pos, const T & ele);

    iterator erase(iterator pos);

    iterator erase(iterator start, iterator end);

    iterator begin();

    const_iterator begin() const;

    iterator end();

    const_iterator end() const;

    int capacity() const;

    static const int SPARE_CAPACITY = 16;

private:
    int theSize;
    int theCapacity;
    T *objects;
};

template<class T>
Vector<T>::Vector(int initSize) :theSize{initSize}, theCapacity{initSize + SPARE_CAPACITY} {
    objects = new T[theCapacity];
}

template<class T>
Vector<T>::Vector(const Vector &rhs):theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{nullptr} {
    objects = new T[theCapacity];
    for (int i = 0; i < theSize; ++i) {
        objects[i] = rhs.objects[i];
    }
}

template<class T>
Vector<T>::Vector(const Vector &&rhs):theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{rhs.objects} {
    rhs.theSize = 0;
    rhs.theCapacity = 0;
    rhs.objects = nullptr;
}

template<class T>
void Vector<T>::clear() {

}

#endif //DS_VECTOR_H
