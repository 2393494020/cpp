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

    // tree.contains(-3);

    // for (int k = 0; k < 15; ++k)
    //     tree.insert(random(100));

    // tree.contains(random(100));
    tree.insert(62);
    tree.insert(88);
    tree.insert(58);
    tree.insert(47);
    tree.insert(35);
    tree.insert(73);
    tree.insert(51);
    tree.insert(99);
    tree.insert(37);
    tree.insert(93);
    tree.insert(36);
    tree.insert(39);
    tree.insert(42);
    tree.insert(62);

    tree.preOrderPrintTree();  // 3 1 2 5 4 6
    tree.inOrderPrintTree();   // 1 2 3 4 5 6
    tree.postOrderPrintTree(); // 2 1 4 6 5 3

    return 0;
}