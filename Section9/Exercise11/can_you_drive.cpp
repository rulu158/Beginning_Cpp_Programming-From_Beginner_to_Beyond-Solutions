#include <iostream>
using namespace std;

void can_you_drive(int age) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    
    if (age >= 16) {
        cout << "Yes - you can drive!";
    } else {
        int diff {16 - age};
        cout << "Sorry, come back in " << diff << " years";
    }
    
    //----WRITE YOUR CODE ABOVE THIS LINE----
}
