#include <iostream>
#include <string>

int sum_of_digits(int n) {
    // Write your code below this line
    
    std::string n_string = std::to_string(n);
    if (n_string.length() == 1) {
        return n;
    }
    
    int num = std::stoi(n_string.substr(0,1));
    int next_n {std::stoi(n_string.substr(1))};
    return num + sum_of_digits(next_n);
    
    // Write your code above this line
}
