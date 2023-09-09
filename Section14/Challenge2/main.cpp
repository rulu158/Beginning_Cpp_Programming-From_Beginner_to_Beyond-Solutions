#include <iostream>
#include "Mystring.h"

int main() {
    Mystring s1 {"Hello"};
    (2 * s1).display();

    Mystring s2{s1 * 2};
    s2.display();
    s2 = s1 * 2;
    s2.display();

    return 0;
}