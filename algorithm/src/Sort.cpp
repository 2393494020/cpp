//
// Created by juno on 19-3-29.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

void quickSort(int list[], int, int);
void bubbleSort(int list[], int);

int main() 
{
    int size = 3;
    // int list[size] = {4, 7, 2, 6, 4, 5, 1};
    int list[size] = {1, 4, 2};
    // for (int i = 0; i < size; ++i) {
    //     list[i] = i + 1;
    // }

    // for (int i = 1; i < size; ++i)
    // {
    //     int j = rand() % i;
    //     swap(list[i], list[j]);
    // }

    quickSort(list, 0, size - 1);
    // bubbleSort(list, size);

    int *last = &list[size];
    for (int *p = list; p < last; ++p) {
        cout << *p << endl;
    }

    // cout << sizeof(list) << endl;
    // cout << sizeof(list[0]) << endl;

    // auto n = end(list) - begin(list);
    // cout << "size:" << n << endl;

    return 0;
}

void quickSort(int list[], int l, int h)
{
    cout << "l,h:" << l << "," << h << endl;
    if (l < h)
    {
        int x = list[0];
        int i = l;
        int j = h;

        while (i < j)
        {
            while (i < j && list[j] > x)
            {
                --j;
            }
            if (i < j)
                list[i++] = list[j];

            while (i < j && list[i] < x)
            {
                ++i;
            }
            if (i < j)
                list[j--] = list[i];
        }

        list[i] = x;



        for (int k = 0; k <= h - l; ++k)
            cout << list[k] << ",";
        cout << endl;
        cout << "i:" << i << endl;

        quickSort(list, l, i - 1);
        quickSort(&list[i + 1], i + 1, h);
    }
}

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