#include <cctype>
#include <cstring>
#include <utility>
#include "Mystring.h"

Mystring::Mystring()
        : str{nullptr} {
    str = new char[1];
    str[0] = '\0';
}

Mystring::Mystring(const char *s)
        : str{nullptr} {
    str = new char[std::strlen(s) + 1];
    std::strcpy(str, s);
}

Mystring::Mystring(std::string &s)
        : str{nullptr} {
    str = new char[s.length() + 1];
    std::strcpy(str, s.c_str());
}

Mystring::Mystring(const Mystring &source)
        : str{nullptr} {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

Mystring::Mystring(Mystring &&source) 
        : str{source.str} {
    source.str = nullptr;
}

Mystring::~Mystring() {
    delete [] str;
}

Mystring &Mystring::operator=(const Mystring &rhs) {
    if (this == &rhs) {
        return *this;
    }
    delete [] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

Mystring &Mystring::operator=(Mystring &&rhs) {
    if (this == &rhs) {
        return *this;
    }
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

Mystring &Mystring::operator+=(const Mystring &rhs) {
    Mystring temp {*this + rhs};
    delete [] str;
    str = new char[std::strlen(temp.str) + 1];
    std::strcpy(str, temp.str);
    return *this;
}

Mystring &Mystring::operator*=(int rhs) {
    Mystring temp {(*this) * rhs};
    delete [] str;
    str = new char[std::strlen(temp.str) + 1];
    std::strcpy(str, temp.str);
    return *this;
}

Mystring Mystring::operator+() const {
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i {0}; i < std::strlen(buff); i++) {
        buff[i] = std::toupper(buff[i]);
    }
    Mystring new_mystr {buff};
    delete [] buff;
    return new_mystr;
}

Mystring Mystring::operator-() const {
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i {0}; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring new_mystr {buff};
    delete [] buff;
    return new_mystr;
}

Mystring &Mystring::operator++() {
    Mystring temp {+(*this)};
    delete [] str;
    str = new char[std::strlen(temp.str)];
    std::strcpy(str, temp.str);
    return *this;
}

Mystring Mystring::operator++(int) {
    Mystring temp {*this};
    operator++();
    return temp;
}

Mystring &Mystring::operator--() {
    Mystring temp {-(*this)};
    delete [] str;
    str = new char[std::strlen(temp.str)];
    std::strcpy(str, temp.str);
    return *this;
}

Mystring Mystring::operator--(int) {
    Mystring temp {*this};
    operator--();
    return temp;
}

bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str));
}

bool Mystring::operator!=(const Mystring &rhs) const {
    return !(*this == rhs);
}

bool Mystring::operator<(const Mystring &rhs) const {
    Mystring mystr_left {-(*this)};
    Mystring mystr_right {-(rhs)};
    int cmp {std::strcmp(mystr_left.str, mystr_right.str)};
    if (cmp < 0) {
        return true;
    }
    return false;
}

bool Mystring::operator<=(const Mystring &rhs) const {
    Mystring mystr_left {-(*this)};
    Mystring mystr_right {-(rhs)};
    int cmp {std::strcmp(mystr_left.str, mystr_right.str)};
    if (cmp < 0 || cmp == 0) {
        return true;
    }
    return false;
}

bool Mystring::operator>(const Mystring &rhs) const {
    Mystring mystr_left {-(*this)};
    Mystring mystr_right {-(rhs)};
    int cmp {std::strcmp(mystr_left.str, mystr_right.str)};
    if (cmp > 0) {
        return true;
    }
    return false;
}

bool Mystring::operator>=(const Mystring &rhs) const {
    Mystring mystr_left {-(*this)};
    Mystring mystr_right {-(rhs)};
    int cmp {std::strcmp(mystr_left.str, mystr_right.str)};
    if (cmp == 0 || cmp > 0) {
        return true;
    }
    return false;
}

Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring new_mystr {buff};
    delete [] buff;
    return new_mystr;
}

Mystring Mystring::operator*(int rhs) const {
    if (rhs <= 0) {
        return Mystring{""};
    }
    char *buff = new char[std::strlen(str) * rhs + 1];
    for (int i {0}; i < rhs; i++) {
        if (i == 0) {
            std::strcpy(buff, str);
        } else {
            std::strcat(buff, str);
        }
    }
    Mystring new_mystr {buff};
    delete [] buff;
    return new_mystr;
}

const char *Mystring::get_str() const {
    return str;
}

int Mystring::get_length() const {
    return std::strlen(str);
}

void Mystring::display() const {
    std::cout << "str: " << str << "; length: " << get_length() << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Mystring &obj) {
    os << obj.str;
}

std::istream &operator>>(std::istream &is, Mystring &obj) {
    std::string input;
    is >> input;
    delete [] obj.str;
    obj = Mystring(input);
    return is;
}