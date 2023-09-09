// Section 14
// Mystring - starting point
#include <iostream>
#include <utility>
#include "Mystring.h"

using namespace std;

int main() {
    /*Mystring empty;                      // no-args constructor
    Mystring larry("Larry");             // overloaded constructor
    Mystring stooge {larry};            // copy constructor 
    
    empty.display();
    larry.display();
    stooge.display();*/

//    Mystring a0 {std::move(Mystring{"Hola "} + Mystring{"mundo"})};
//    a0.display();

    /*
    Mystring a{"Hello"};
    a = Mystring{"Hola"};
    a = "Bonjour";

    std::string hallo = "Hallo";
    a = hallo;

    Mystring a2{"asd"};
    a = a2;

    a = a + "HOLA";

    a.display();
    */

    Mystring a1 {"Hello"};
    Mystring a2 {"Hola"};
    Mystring a3 {"Hallo"};

    Mystring a {};
    a = a1 = a2 = a3;

    a.display();
    
    return 0;
}

