#include "car.hpp"
#include <iostream>
#include <string>

jan::car::car()
{
}

jan::car::car(std::string& brand)
{
	std::cout << "Your car brand is " << brand << std::endl;
}

jan::car::~car()
{
}