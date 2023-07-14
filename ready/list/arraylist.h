#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include <iostream>
#include "linearlist.h"

using namespace std;

#define DEFAULT_SIZE 15

template <class T>
class ArrayList : public LinearList<T>
{
protected:
    T *data;
    size_t capacity;
    size_t length;
public:
    // 默认构造函数
    ArrayList();
    // copy构造函数
    ArrayList(ArrayList<T> &arrayList);
    // remove构造函数
    ArrayList(ArrayList<T> &&arrayList);
    ArrayList(size_t capacity_);
    ~ArrayList();

    size_t size() const;
    T operator[](size_t i) const;
    void traverse() const;
    void push_back(const T &value);

};

// ------impl------

template <class T>
ArrayList<T>::ArrayList()
{
    data = new T[DEFAULT_SIZE];
    capacity = DEFAULT_SIZE;
    length = 0;
    cout << "default construct" << endl;
}

template <class T>
ArrayList<T>::ArrayList(ArrayList<T> &arrayList) : capacity(arrayList.capacity), length(arrayList.length)
{
    data = new T[capacity];
    for (size_t i = 0; i < length; i++)
    {
        data[i] = arrayList.data[i];
    }
    cout << "copy construct" << endl;
}

template <class T>
ArrayList<T>::ArrayList(ArrayList<T> &&arrayList) : capacity(arrayList.capacity), length(arrayList.length)
{
    data = arrayList.data;
    arrayList.data = nullptr;
    cout << "remove construct" << endl;
}

template <class T>
ArrayList<T>::ArrayList(size_t capacity_) : capacity(capacity_)
{
    data = new T[capacity_];
    length = 0;
    cout << "construct: require capacity" << endl;
}

template <class T>
ArrayList<T>::~ArrayList()
{
    delete[] data;
    data = nullptr;
    cout << "destroy" << endl;
}

template <class T>
size_t ArrayList<T>::size() const
{
    return length;
}

template <class T>
T ArrayList<T>::operator[](size_t i) const
{
    if (0 <= i && i < length)
    {
        return data[i];
    }
    throw out_of_range("out of array index");
}

template <class T>
void ArrayList<T>::push_back(const T &value)
{
    if (length == capacity)
    {
        T *old_data = data;
        data = new T[length * 2];
        for (size_t i = 0; i < length; i++)
        {
            data[i] = old_data[i];
        }
        delete[] old_data;
        capacity = length * 2;
    }
    data[length] = value;
    length++;
    // cout << "capacity:" << capacity << " length:" << length << endl;
}

template <class T>
void ArrayList<T>::traverse() const
{
    cout << "1 = " << data[0] << endl;
    cout << length << " = " << data[length - 1] << endl;
}

#endif
