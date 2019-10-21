//============================================================================
// Name        : Exercise4.cpp
// Author      : Olena Lizina
// Description : Exercise 4
//============================================================================

#include <iostream>
#include <iomanip>

enum BASE
{
	DECIMAL,
	OCTAL,
	HEXADECIMAL
};

void displayInBases(const int number, const BASE numberBase)
{
	switch(numberBase)
	{
	case DECIMAL:
		std::cout << "Your input in octal with base: "
				  << std::showbase << std::oct << number
				  << ", without base: " << std::noshowbase << std::oct << number << std::endl;
		std::cout << "Your input in hexadecimal with base: "
				  << std::showbase << std::hex << number
				  << ", without base: " << std::noshowbase << std::hex << number << std::endl;
		break;
	case OCTAL:
		std::cout << "Your input in hexadecimal with base: "
				  << std::showbase << std::hex << number
				  << ", without base: " << std::noshowbase << std::hex << number << std::endl;
		std::cout << "Your input in decimal with base: "
				  << std::showbase << std::dec << number
				  << ", without base: " << std::noshowbase << std::dec << number << std::endl;
		break;
	case HEXADECIMAL:
		std::cout << "Your input in octal with base: "
				  << std::showbase << std::oct << number
				  << ", without base: " << std::noshowbase << std::oct << number << std::endl;
		std::cout << "Your input in decimal with base: "
				  << std::showbase << std::dec << number
				  << ", without base: " << std::noshowbase << std::dec << number << std::endl;
		break;
	}
}

int main(int argc, char **argv)
{
	int integer;

	while(true)
	{
		std::cout << "Enter the decimal value: ";
		std::cin >> std::dec >> integer;
//		std::cin >> std::setbase(10) >> integer;
		displayInBases(integer, BASE::DECIMAL);

		std::cout << "Enter the hexadecimal value: ";
		std::cin >> std::hex >> integer;
//		std::cin >> std::setbase(16) >> integer;
		displayInBases(integer, BASE::HEXADECIMAL);

		std::cout << "Enter the octal value: ";
		std::cin >> std::oct >> integer;
//		std::cin >> std::setbase(8) >> integer;
		displayInBases(integer, BASE::OCTAL);
	}

	return 0;
}
