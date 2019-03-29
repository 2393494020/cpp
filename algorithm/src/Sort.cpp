//
// Created by juno on 19-3-29.
//

#include <iostream>

using namespace std;

void bubbleSort(int list[], int size) {

    for (int j = size - 1; j > 0; --j) {
        for (int i = 0; i < j; ++i) {
            if (list[i] > list[i + 1]) {
                int temp = list[i + 1];
                list[i + 1] = list[i];
                list[i] = temp;
            }
        }
        std::cout << list[j] << std::endl;
    }

    std::cout << std::endl;


    for (int i = 0; i < size; ++i) {
        std::cout << list[i] << std::endl;
    }
}

int main() {
    int list[] = {9, 8, 7, 5, 6, 4, 3, 2, 1};
    int size = 9;
    bubbleSort(list, size);

    return 0;
}
