//
// Created by juno on 19-3-29.
//

#include <iostream>

using namespace std;

void bubbleSort(int list[], int size) {

    for (int j = size; j > 0; --j) {
        for (int i = 0; i < j; ++i) {
            if (list[i] > list[j]) {
                int temp = list[j];
                list[j] = list[i];
                list[i] = temp;
            }
        }
    }


    for (int i = 0; i < size; ++i) {
        std::cout << list[i] << std::endl;
    }
}

int main() {
    int list[] = {33, 90, 40, 30, 70, 80, 55, 230, 199};
    int size = 9;
    bubbleSort(list, size);

    return 0;
}