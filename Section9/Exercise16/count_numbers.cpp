#include <iostream>
#include <vector>
using namespace std;

int count_numbers(const vector<int> &vec) {
    //---- WRITE YOUR CODE BELOW THIS LINE----
    
    bool found {false};
    int count {};
    
    while (!found && count < vec.size()) {
        if (vec[count] == -99) {
            found = true;
        } else {
            ++count;
        }
    }
    
    //---- WRITE YOUR CODE ABOVE THIS LINE----
    //---- DO NOT MODIFY THE CODE BELOW THIS LINE-----
    return count;
}
