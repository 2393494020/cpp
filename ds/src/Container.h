//
// Created by juno on 19-3-28.
//

#ifndef DS_CONTAINER_H
#define DS_CONTAINER_H

template<typename T>
class Container {
public:
    virtual ~Container() {};

    virtual bool empty() const = 0;

    virtual int size() const = 0;

    virtual T &head() = 0;

    virtual T &last() = 0;

    virtual void pop() = 0;

    virtual void push(const T &theElement) = 0;
};


#endif //DS_CONTAINER_H
