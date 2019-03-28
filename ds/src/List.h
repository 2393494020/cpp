//
// Created by juno on 19-3-28.
//

#ifndef DS_LIST_H
#define DS_LIST_H

#include "Container.h"

template<class T>
class List : public Container<T> {
public:
    ~List<T>() {
        delete[]objects;
    }

private:
    int theSize;
    T *objects;
};

#endif //DS_LIST_H
