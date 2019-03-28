#include <iostream>

#include "Vector.h"

using namespace std;


int main() {
    Vector<int> v(10);
    std::cout << v.size() << std::endl;
    return 0;
}