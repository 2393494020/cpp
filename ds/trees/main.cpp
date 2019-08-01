#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "BinarySearchTree.h"

using namespace std;

#define random(x) (rand() % x)

int main()
{
    srand((int)time(0));

    BinarySearchTree<int> tree;
    tree.insert(3);
    tree.insert(1);
    tree.insert(2);
    tree.insert(5);
    tree.insert(6);
    tree.insert(4);
    // tree.insert(11);
    // tree.insert(5);
    // tree.insert(3);
    // tree.insert(2);
    // tree.insert(9);
    // tree.insert(6);
    // tree.insert(4);
    // tree.insert(7);
    // tree.insert(10);
    // tree.insert(16);
    // tree.insert(13);
    // tree.insert(19);
    // tree.insert(11);

    // cout << ((tree.contains(19) == true) ? "true" : "false") << endl;

    // for (int k = 0; k < 15; ++k)
    //     tree.insert(random(100));

    // tree.contains(random(100));

    tree.preOrderPrintTree();  // 3 1 2 5 4 6
    tree.inOrderPrintTree();   // 1 2 3 4 5 6
    tree.postOrderPrintTree(); // 2 1 4 6 5 3

    return 0;
}