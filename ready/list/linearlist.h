#ifndef LINEARLIST_H_
#define LINEARLIST_H_

template <class T>
class LinearList {
public:
    virtual size_t size() const = 0;
    virtual void push_back(const T &value) = 0;
};

#endif
