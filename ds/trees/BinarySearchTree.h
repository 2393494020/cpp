#ifndef DS_TREES_BINARY_SEARCH_TREE_H
#define DS_TREES_BINARY_SEARCH_TREE_H

#include <iostream>

using namespace std;

template<typename Comparable>
class BinarySearchTree
{
public:
    
    BinarySearchTree();

    BinarySearchTree( const BinarySearchTree & rhs );

    BinarySearchTree( BinarySearchTree && rhs );

    const Comparable findMin() const;

    const Comparable findMax() const;

    bool contains( const Comparable & x ) const;
    
    bool isEmpty();

    void printTree( ostream & out = cout ) const;

    void makeEmpty();

    void insert( const Comparable & x );

    void insert( Comparable & x );

    void remove( const Comparable & x );

    BinarySearchTree & operator= ( const BinarySearchTree & rhs );

    BinarySearchTree & operator= ( BinarySearchTree && rhs );
    
    ~BinarySearchTree();

private:

    struct BinaryNode
    {
        Comparable item;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode( const Comparable & newItem, BinaryNode * lt, BinaryNode * rt ) : item { newItem }, left { lt }, right { rt }
        {}

        BinaryNode( Comparable && newItem, BinaryNode * lt, BinaryNode * rt ) : item { std::move( newItem ) }, left { lt }, right { rt }
        {}
    };
    

};

template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree()
{
}

template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree( const BinarySearchTree & rhs )
{
}

template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree( BinarySearchTree && rhs )
{
}

template<typename Comparable>
BinarySearchTree<Comparable> & BinarySearchTree<Comparable>::operator= ( const BinarySearchTree & rhs )
{
}

template<typename Comparable>
BinarySearchTree<Comparable> & BinarySearchTree<Comparable>::operator= ( BinarySearchTree && rhs )
{
}

template<typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
}

template<typename Comparable>
bool BinarySearchTree<Comparable>::isEmpty()
{
}

template<typename Comparable>
void BinarySearchTree<Comparable>::printTree( ostream & out ) const
{
    out << "start print binary search tree";
}

#endif