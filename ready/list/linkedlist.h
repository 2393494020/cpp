#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include "linearlist.h"

using namespace std;

template <class T>
class LinkedList : public LinearList<T>
{
protected:
    class Node
    {
    public:
        T *data;
        Node *next;
    public:
        Node()
        {
            cout << "class Node default construct" << endl;
            data = nullptr;
            next = nullptr;
        }
        Node(const T &value)
        {
            cout << "class Node construct" << endl;
            data = new T(value);
            next = nullptr;
        }
        ~Node()
        {
            if (next != nullptr)
            {
                delete next;
            }
            if (data != nullptr)
            {
                delete data;
            }
            cout << "class Node default destory" << endl;
        }
    };
    Node *head;
    size_t length = 0;

public:
    LinkedList();
    ~LinkedList();
    size_t size() const;
    void push_back(const T &value);
    void print_list();
};

// ------impl------

template <class T>
LinkedList<T>::LinkedList()
{
    head = new Node;
    cout << "construct" << endl;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    delete head;
    cout << "destory" << endl;
}

template <class T>
size_t LinkedList<T>::size() const
{
    return length;
}

template <class T>
void LinkedList<T>::push_back(const T &value)
{
    Node *current = head + length;
    current->next = new Node(value);    
    length ++;
}

template <class T>
void LinkedList<T>::print_list()
{
    Node *current = head + length;
    cout << *((head+1)->data) << endl;
    while (head != current)
    {
        cout << *(current->next->data) << endl;
        current -= 1;
    }
}

#endif // LINKEDLIST_H_
