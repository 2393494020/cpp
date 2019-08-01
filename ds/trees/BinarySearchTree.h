#ifndef DS_TREES_BINARY_SEARCH_TREE_H
#define DS_TREES_BINARY_SEARCH_TREE_H

#include <iostream>

using namespace std;

template <typename Comparable>
class BinarySearchTree
{
public:
    BinarySearchTree();

    BinarySearchTree(const BinarySearchTree &rhs);

    BinarySearchTree(BinarySearchTree &&rhs);

    const Comparable findMin() const;

    const Comparable findMax() const;

    bool contains(const Comparable &x) const;

    bool contains(Comparable &&x) const;

    bool isEmpty() const;

    void preOrderPrintTree(ostream &out = cout) const;

    void inOrderPrintTree(ostream &out = cout) const;

    void postOrderPrintTree(ostream &out = cout) const;

    void makeEmpty();

    void insert(const Comparable &x);

    void insert(Comparable &&x);

    void remove(const Comparable &x);

    BinarySearchTree &operator=(const BinarySearchTree &rhs);

    BinarySearchTree &operator=(BinarySearchTree &&rhs);

    ~BinarySearchTree();

private:
    struct BinaryNode
    {
        Comparable item;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const Comparable &newItem, BinaryNode *lt, BinaryNode *rt) : item{newItem}, left{lt}, right{rt}
        {
        }

        BinaryNode(Comparable &&newItem, BinaryNode *lt, BinaryNode *rt) : item{std::move(newItem)}, left{lt}, right{rt}
        {
        }
    };

    BinaryNode *root;
};

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree()
{
    this->root = nullptr;
}

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree &rhs)
{
}

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(BinarySearchTree &&rhs)
{
}

template <typename Comparable>
BinarySearchTree<Comparable> &BinarySearchTree<Comparable>::operator=(const BinarySearchTree &rhs)
{
}

template <typename Comparable>
BinarySearchTree<Comparable> &BinarySearchTree<Comparable>::operator=(BinarySearchTree &&rhs)
{
}

template <typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
}

template <typename Comparable>
bool BinarySearchTree<Comparable>::isEmpty() const
{
    return this->root == nullptr;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::insert(Comparable &&x)
{
    BinaryNode *currentNode = new BinaryNode{x, nullptr, nullptr};
    if (this->isEmpty())
    {
        this->root = currentNode;
        cout << "root:[" << x << "]" << endl;
    }
    else
    {
        BinaryNode *parentNode = this->root;
        BinaryNode *subParentNode = this->root;
        while (subParentNode != nullptr)
        {
            parentNode = subParentNode;
            if (subParentNode->item > x)
            {
                subParentNode = subParentNode->left;
            }
            else if (subParentNode->item < x)
            {
                subParentNode = subParentNode->right;
            }
            else
            {
                break;
            }
        }

        bool insertFlag = true;
        if (parentNode->item > x)
        {
            parentNode->left = currentNode;
        }
        else if (parentNode->item < x)
        {
            parentNode->right = currentNode;
        }
        else
        {
            insertFlag = false;
        }
        
        if (insertFlag)
        {
            cout << "insert:[" << x << "], parent:[" << (parentNode->item) << "]" << endl;
        }
        else
        {
            cout << "ignore:[" << x << "]" << endl;
        }
        
    }
}

template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(Comparable &&x) const
{
    if (this->isEmpty())
        return false;

    BinaryNode *targetNode = this->root;
    while (targetNode != nullptr && targetNode->item != x)
    {
        if (targetNode->item > x)
        {
            targetNode = targetNode->left;
        }
        else
        {
            targetNode = targetNode->right;
        }
    }

    if (targetNode != nullptr && targetNode->item == x)
    {
        return true;
    }
    
    return false;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::preOrderPrintTree(ostream &out) const
{
    out << "preOrder print binary search tree" << endl;
    BinaryNode *targetNode = this->root;
    while (targetNode != nullptr)
    {
    }
    
}

template <typename Comparable>
void BinarySearchTree<Comparable>::inOrderPrintTree(ostream &out) const
{
    out << "inOrder print binary search tree" << endl;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::postOrderPrintTree(ostream &out) const
{
    out << "postOrder print binary search tree" << endl;
}

#endif