#include <iostream>

#include "BinarySearchTree.h"

using namespace std;

int main()
{
    BinarySearchTree<int> tree;
    
    tree.insert(11);
    tree.insert(5);
    tree.insert(9);
    tree.insert(6);
    tree.insert(7);
    tree.insert(2);

    cout << tree.contains(87) << endl;

    tree.preOrderPrintTree();

    return 0;
}