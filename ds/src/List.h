//
// Created by juno on 19-3-28.
//

#ifndef DS_LIST_H
#define DS_LIST_H

#include "Container.h"

template<class T>
class List : public Container<T> {
public:
    explicit List<T>(int initSize = 0);

    ~List<T>() {
    }

    void push_back(const T & ele);

    void pop_back();

    const T & back();

    const T & front();

    void push_front(const T & ele);

    void pop_front();

    T & operator[] (int idx);

    T & at(int idx);

    int capacity() const;

    void reserve(int newCapacity);

    iterator insert(iterator pos, const T & ele);

    iterator erase(iterator pos);

private:
    int theSize;
};

template<class T>
void List<T>::push_back(const T & ele) {

}

#endif //DS_LIST_H
