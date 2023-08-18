// You do NOT have to write a main() function. The main() function is written by me
// behind the scenes to call your function and test your code.
#include <string>

std::string reverse_string(const std::string &str) {
    std::string reversed;
    // Write your code below this line 
    for (size_t i {str.length()}; i-- > 0;) {
        reversed += str[i];
    }
    // Write your code abocve this line
    return reversed;
}
