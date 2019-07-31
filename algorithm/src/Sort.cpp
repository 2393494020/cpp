//
// Created by juno on 19-3-29.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

void quickSort(int randomList[], int, int);
void bubbleSort(int randomList[], int);

int main(int argc, char* argv[]) 
{
    char * input = argv[1];
    int size = atoi(input);
    int *randomList = new int[size];
    for (int i = 0; i < size; ++i) {
        randomList[i] = i + 1;
    }

    for (int i = 1; i < size; ++i)
    {
        int j = rand() % i;
        swap(randomList[i], randomList[j]);
    }

    int head = randomList[0];

    quickSort(randomList, 0, size - 1);
    // bubbleSort(randomList, size);

    int *last = &randomList[size];
    // for (int *p = randomList; p < last; ++p) 
    // {
    //     cout << *p << endl;
    // }

    cout << endl << "size:" << size << endl;
    cout << "before sorted head:" << head << endl;
    cout << "after  sorted last:" << *(--last) << endl;

    // cout << sizeof(randomList) << endl;
    // cout << sizeof(randomList[0]) << endl;

    // auto n = end(randomList) - begin(randomList);
    // cout << "size:" << n << endl;
    delete randomList;

    return 0;
}

void quickSort(int randomList[], int l, int h)
{
    if (l < h)
    {
        int x = randomList[l];
        int i = l;
        int j = h;

        while (i < j)
        {
            while (i < j && randomList[j] > x)
            {
                --j;
            }
            if (i < j)
                randomList[i++] = randomList[j];

            while (i < j && randomList[i] < x)
            {
                ++i;
            }
            if (i < j)
                randomList[j--] = randomList[i];
        }

        randomList[i] = x;

        quickSort(randomList, l, i - 1);
        quickSort(randomList, i + 1, h);
    }
}

void bubbleSort(int randomList[], int size)
{
    for (int j = size - 1; j > 0; --j) 
    {
        for (int i = 0; i < j; ++i) 
        {
            if (randomList[i] < randomList[i + 1]) 
            {
                int temp = randomList[i + 1];
                randomList[i + 1] = randomList[i];
                randomList[i] = temp;
            }
        }
    }
}