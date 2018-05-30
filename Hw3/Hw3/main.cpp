#include "Integration.h"
#include <iostream>
#include <cmath>

int main()
{
	DefInt MyInt(1, 2, f1);
	std::cout << "Using Trapezoidal Method: " << MyInt.ByTrapezoid(100) << std::endl;
	std::cout << "Using Simpson's Method: " << MyInt.BySimpsons(100) << std::endl;
	int stop;
	std::cin >> stop;
}