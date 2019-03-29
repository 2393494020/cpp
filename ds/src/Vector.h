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

    bool empty() const {
        return size() == 0;
    }

    int size() const {
        return theSize;
    }

    T &head() {
        return objects[0];
    }

    T &last() {
        return objects[0];
    }

    void pop() {
        if (theSize > 0)
            theSize -= 1;
        else
            theSize = 0;
    }

    void push(const T &theElement);

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
void Vector<T>::push(const T &theElement) {

}

#endif //DS_VECTOR_H
