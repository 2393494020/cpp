#include "car.hpp"
#include <iostream>
#include <string>

int main() {
	std::string brand = "bmw";
	jan::car bmw = jan::car(brand);
	std::cout << sizeof(bmw) << std::endl;
	return 0;
}