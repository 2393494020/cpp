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
    }
    else
    {
        BinaryNode *existNode = this->root;
        // only root
        if (existNode->left == nullptr && existNode->right == nullptr)
        {
            if (existNode->item > x)
            {
                existNode->left = currentNode;
            }
            else
            {
                existNode->right = currentNode;
            }
        }
        else
        {
            bool insertFlag = false;
            while (!insertFlag && existNode->left != nullptr && existNode->item > x)
            {
                BinaryNode *subNode = existNode->left;
                if (subNode->left == nullptr && subNode->right == nullptr)
                {
                    if (subNode->item > x)
                    {
                        subNode->left = currentNode;
                    }
                    else
                    {
                        subNode->right = currentNode;
                    }
                    insertFlag = true;
                }
                existNode = subNode;
            }
            while (!insertFlag && existNode->right != nullptr && existNode->item < x)
            {
                BinaryNode *subNode = existNode->right;
                if (subNode->left == nullptr && subNode->right == nullptr)
                {
                    if (subNode->item > x)
                    {
                        subNode->left = currentNode;
                    }
                    else
                    {
                        subNode->right = currentNode;
                    }
                    insertFlag = true;
                }
                existNode = subNode;
            }
            cout << "insert:" << insertFlag << endl;
        }
    }
}

template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(Comparable &&x) const
{
    if (this->isEmpty())
        return false;

    if (this->root->item == x)
    {
        return true;
    }
    else
    {
        cout << "to do" << endl;
        return false;
    }
}

template <typename Comparable>
void BinarySearchTree<Comparable>::preOrderPrintTree(ostream &out) const
{
    out << "preOrder print binary search tree" << endl;
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