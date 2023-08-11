// Letter Pyramid
// Written by Frank J. Mitropoulos
// Refactored by Raul Garcia

#include <iostream>
#include <string>
#include <vector>


int main()
{
    std::string letters{};

    std::cout << "Enter a string of letters so I can create a Letter Pyramid from it: ";
    getline(std::cin, letters);

    size_t num_letters = letters.length();

    std::vector <std::string> rows {};

    // Position related to the position of the user input
    int position {0};

    // For each letter in the string
    for (char c : letters) {
	// num_spaces is the different minus position (which is also the row)
        size_t num_spaces = num_letters - position;

	// Initialize row with num_spaces
	std::string row (num_spaces, ' ');

        // Add letters in order up to the current character to row
        for (size_t j=0; j < static_cast<size_t>(position); j++) {
	    row += letters.at(j);
        }

        // Add the current 'center' character to row
	row += c;

        // Add the remaining characters in reverse order to row
        for (int j = static_cast<size_t>(position)-1; j >=0; --j) {
	    row += letters.at(j);
        }

	// Insert row into rows
	rows.push_back(row);

        ++position;
    }

    // Display all rows
    for (std::string row : rows) {
	std::cout << row << std::endl;
    }

    return 0;
}
