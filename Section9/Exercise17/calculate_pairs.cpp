#include <iostream>
#include <vector>
using namespace std;

int calculate_pairs(vector<int> vec) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    
    if (vec.size() <= 1) {
        return 0;
    }
    
    int result{};
    
    for (size_t i{}; i < vec.size(); i++) {
        for (size_t j{i+1}; j < vec.size(); j++) {
            result += vec.at(i) * vec.at(j);
        }
    }
    
    cout << endl;
     
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    return result;
}
