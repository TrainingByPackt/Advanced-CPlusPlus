//============================================================================
// Name        : Exercise5.cpp
// Author      : Olena Lizina
// Description : Exercise 5
//============================================================================

#include <iostream>
#include <iomanip>

template< typename FloatingPoint >
void formattingPrint(const FloatingPoint number)
{
	auto precision = std::cout.precision();
	std::cout << "Default formatting with point: "
			  << std::showpoint << number << std::endl
	          << "Default formatting without point: "
			  << std::noshowpoint << number << std::endl
	          << "Fixed formatting: "
			  << std::fixed << number << std::endl
	          << "Scientific formatting: "
	          << std::scientific << number << std::endl
	          << "Hexfloat formatting: "
	          << std::hexfloat << number << std::endl
	          << "Defaultfloat formatting: "
			  << std::defaultfloat << number << std::endl;

	for (int i = 0; i < 22; i++)
	{
		std::cout << "Precision: " << i << ", number: " << std::setprecision(i) << number << std::endl;
	}
	std::cout << std::setprecision(precision);
}

int main(int argc, char **argv)
{
	float floatNum;
	double doubleNum;
	long double longDoubleNum;

	while(true)
	{
		std::cout << "Enter the floating-point digit: ";
		std::cin >> std::setprecision(36) >> longDoubleNum;

		std::cout << "long double output" << std::endl;
		formattingPrint(longDoubleNum);
		doubleNum = longDoubleNum;
		std::cout << "double output" << std::endl;
		formattingPrint(doubleNum);
		floatNum = longDoubleNum;
		std::cout << "float output" << std::endl;
		formattingPrint(floatNum);
	}

	return 0;
}
