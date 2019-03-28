//
// Created by juno on 19-3-28.
//

#ifndef DS_VECTOR_H
#define DS_VECTOR_H

#include "Container.h"

template<class T>
class Vector : public Container<T> {
public:
    explicit Vector(int initSize = 0);

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
void Vector<T>::push(const T &theElement) {

}

#endif //DS_VECTOR_H
