#include <iostream>

#include "BinarySearchTree.h"

using namespace std;


int main()
{
    BinarySearchTree<int> tree;
    
    tree.insert(11);
    tree.insert(5);
    tree.insert(3);
    tree.insert(2);
    tree.insert(9);
    tree.insert(6);
    tree.insert(4);
    tree.insert(7);
    tree.insert(10);
    tree.insert(16);
    tree.insert(13);
    tree.insert(19);
    tree.insert(11);

    cout << ((tree.contains(19) == true) ? "true" : "false") << endl;

    tree.preOrderPrintTree();

    return 0;
}