#include <iostream>

#include "Vector.h"

using namespace std;

// recursive
int fact(int num) {
    if (num == 0)
        return 1;
    return num * fact(num - 1);
}

int main() {
    std::cout << fact(10) << std::endl;
    return 0;
}

