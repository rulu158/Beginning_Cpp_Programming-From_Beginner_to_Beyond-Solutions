// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <iomanip>
#include <fstream>

int main() {
    std::ifstream in_file {"romeoandjuliet"};
    if (!in_file) {
        std::cerr << "Could not open input file." << std::endl;
        return 1;
    }
    std::ofstream out_file {"romeoandjuliet_numbered"};
    if (!out_file) {
        std::cerr << "Could not open output file." << std::endl;
        return 1;
    }

    std::string line {};
    int counter {1};
    while (std::getline(in_file, line)) {
        out_file << std::setw(4) << std::right << counter
                << ": " << line << std::endl;
        counter++;
    }

    in_file.close();
    out_file.close();
    
    return 0;
}

