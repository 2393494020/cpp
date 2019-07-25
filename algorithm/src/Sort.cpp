//
// Created by juno on 19-3-29.
//

#include <iostream>

using namespace std;

void bubbleSort(int list[], int size)
{
    for (int j = size - 1; j > 0; --j) {
        for (int i = 0; i < j; ++i) {
            if (list[i] < list[i + 1]) {
                int temp = list[i + 1];
                list[i + 1] = list[i];
                list[i] = temp;
            }
        }
    }
}

int main() 
{
    int size = 10000;
    int list[size] = {};
    for (int i = 0; i < size; ++i) {
        list[i] = i + 1;
    }

    bubbleSort(list, size);

    int *last = &list[size];
    for (int *p = list; p < last; ++p) {
        cout << *p << endl;
    }

    // auto n = end(list) - begin(list);
    // cout << "size:" << n << endl;

    return 0;
}
