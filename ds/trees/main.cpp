#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <glog/logging.h>
#include "BinarySearchTree.h"

using namespace std;

#define random(x) (rand() % x)

int main(int argc, char *argv[])
{
    // google::InitGoogleLogging(argv[0]);

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

    for (int k = 0; k < 15; ++k)
        tree.insert(random(100));

    tree.contains(random(100));
    try
    {
        int min = tree.findMin();
        int max = tree.findMax();
        // LOG(INFO) << "min:[" << min << "]\n";
        // LOG(INFO) << "max:[" << max << "]\n";
    }
    catch (const char *error)
    {
        // LOG(ERROR) << "error:[" << error << "]\n";
    }

    // tree.preOrderPrintTree();
    // tree.inOrderPrintTree();
    // tree.postOrderPrintTree();

    // google::ShutdownGoogleLogging();

    return 0;
}