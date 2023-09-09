#include <iostream>
#include "Mystring.h"

int main() {
    Mystring s1 {"Hello"};
    Mystring s2 {"world"};

    Mystring s3 {(s1 *= 3)};
    s3.display();
    s1.display();

    (++s2).display();
    s2.display();

    return 0;
}