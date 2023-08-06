#include <iostream>

int main() {
	int favNum;

	std::cout << "Enter your favorite number between 1 and 100: ";

	std::cin >> favNum;

	std::cout << std::endl << "Amazing!! That's my favorite number too!" << std::endl
		<< "No really!!, " << favNum << " is my favorite number!" << std::endl;
	return 0;
}
