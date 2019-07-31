#include <iostream>

#include "BinarySearchTree.h"

using namespace std;

int main()
{
    BinarySearchTree<int> tree;
    
    tree.insert(11);
    tree.insert(5);
    tree.insert(6);

    cout << tree.contains(87) << endl;

    tree.preOrderPrintTree();

    return 0;
}