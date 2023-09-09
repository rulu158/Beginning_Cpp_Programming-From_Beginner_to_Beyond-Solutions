#include <cstring>
#include <cctype>
#include <iostream>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s)+1];
            std::strcpy(str, s);
        }
}

// Overloaded constructor
Mystring::Mystring(std::string s) 
    : str {nullptr} {
        str = new char[s.length()+1];
        std::strcpy(str, s.c_str());
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
     : str{nullptr} {
        str = new char[std::strlen(source.str )+ 1];
        std::strcpy(str, source.str);
}

// Move constructor
Mystring::Mystring(Mystring &&source) 
     : str{source.str} {
        source.str = nullptr;
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
int Mystring::get_length() const { return std::strlen(str); }
 
// string getter
const char *Mystring::get_str() const { return str; }

// copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
    if (this == &rhs) {
        return *this;
    }

    delete [] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);

    return *this;
}

// copy assignment rvalue
Mystring &Mystring::operator=(Mystring &&rhs) {
    if (this == &rhs) {
        return *this;
    }

    delete [] str;
    str = rhs.str;      // steal the pointer

    rhs.str = nullptr;  // null out the rhs object

    return *this;
}

// minus
Mystring Mystring::operator-() const {
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i = 0; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring new_mystr {buff};
    delete [] buff;
    return new_mystr;
}

// add
Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);

    Mystring new_mystr {buff};
    delete [] buff;

    return new_mystr;
}

bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

bool Mystring::operator!=(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) != 0);
}

std::ostream &operator<<(std::ostream &os, const Mystring &obj) {
    os << obj.str;
    return os;
}

std::istream &operator>>(std::istream &is, Mystring &obj) {
    std::string input;
    is >> input;

    delete [] obj.str;
    /*
    // another way to do it
    obj.str = new char[input.length() + 1];
    std::strcpy(obj.str, input.c_str());
    */
    obj = Mystring(input);

    return is;
}