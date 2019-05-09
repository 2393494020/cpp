//
// Created by juno on 19-3-28.
//

#ifndef DS_LISTS_CONTAINER_H
#define DS_LISTS_CONTAINER_H

template<typename T>
class Container {
public:
    virtual ~Container() {};

    virtual bool empty() const = 0;

    virtual int size() const = 0;

    virtual void clear() = 0;
};


#endif //DS_CONTAINER_H
