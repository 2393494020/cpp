//
// Created by juno on 19-3-29.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

void quickSort(int list[], int, int);
void bubbleSort(int list[], int);

int main(int argc, char* argv[]) 
{
    char * input = argv[1];
    int size = atoi(input);
    int list[size];
    for (int i = 0; i < size; ++i) {
        list[i] = i + 1;
    }

    for (int i = 1; i < size; ++i)
    {
        int j = rand() % i;
        swap(list[i], list[j]);
    }

    int head = list[0];

    quickSort(list, 0, size - 1);
    // bubbleSort(list, size);

    int *last = &list[size];
    for (int *p = list; p < last; ++p) 
    {
        cout << *p << endl;
    }

    cout << endl << "head:" << head << endl;
    cout << "argc:" << argc << endl;
    cout << "size:" << size << endl;

    // cout << sizeof(list) << endl;
    // cout << sizeof(list[0]) << endl;

    // auto n = end(list) - begin(list);
    // cout << "size:" << n << endl;

    return 0;
}

void quickSort(int list[], int l, int h)
{
    if (l < h)
    {
        int x = list[l];
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

        quickSort(list, l, i - 1);
        quickSort(list, i + 1, h);
    }
}

void bubbleSort(int list[], int size)
{
    for (int j = size - 1; j > 0; --j) 
    {
        for (int i = 0; i < j; ++i) 
        {
            if (list[i] < list[i + 1]) 
            {
                int temp = list[i + 1];
                list[i + 1] = list[i];
                list[i] = temp;
            }
        }
    }
}