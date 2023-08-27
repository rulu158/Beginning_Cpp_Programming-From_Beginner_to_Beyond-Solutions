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
    str = new char[std::strlen(source.str)];
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
    str = temp.str;
    temp.str = nullptr;
    return *this;
}

Mystring &Mystring::operator*=(int rhs) {
    Mystring temp {*this * rhs};
    delete [] str;
    str = temp.str;
    temp.str = nullptr;
    return *this;
}

const char *Mystring::get_str() const {
    return str;
}

void Mystring::set_str(const char *s) {
    delete [] str;
    str = new char[std::strlen(s) + 1];
    std::strcpy(str, s);
}

void Mystring::set_str(std::string &s) {
    delete [] str;
    str = new char[s.length() + 1];
    std::strcpy(str, s.c_str());
}

int Mystring::get_length() const {
    return std::strlen(str);
}

void Mystring::display() const {
    std::cout << "str: " << str << "; length: " << get_length() << std::endl;
}

Mystring operator+(const Mystring &obj) {
    char *buff = new char[obj.get_length() + 1];
    std::strcpy(buff, obj.get_str());
    for (int i {0}; i < std::strlen(buff); i++) {
        buff[i] = std::toupper(buff[i]);
    }
    Mystring new_mystr {buff};
    delete [] buff;
    return new_mystr;
}

Mystring operator-(const Mystring &obj) {
    char *buff = new char[obj.get_length() + 1];
    std::strcpy(buff, obj.get_str());
    for (int i {0}; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring new_mystr {buff};
    delete [] buff;
    return new_mystr;
}

Mystring &operator++(Mystring &obj) {
    Mystring upper_mystr {+obj};
    obj.set_str(upper_mystr.get_str());
    return obj;
}

Mystring operator++(Mystring &obj, int) {
    Mystring temp {obj};
    ++obj;
    return temp;
}

Mystring &operator--(Mystring &obj) {
    Mystring lower_mystr {-obj};
    obj.set_str(lower_mystr.get_str());
    return obj;
}

Mystring operator--(Mystring &obj, int) {
    Mystring temp {obj};
    --obj;
    return temp;
}

bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.get_str(), rhs.get_str()) == 0);
}

bool operator!=(const Mystring &lhs, const Mystring &rhs) {
    return !(lhs == rhs);
}

bool operator<(const Mystring &lhs, const Mystring &rhs) {
    Mystring left {-lhs};
    Mystring right {-lhs};
    int cmp = std::strcmp(left.get_str(), right.get_str());
    if (cmp < 0) {
        return true;
    } else {
        return false;
    }
}

bool operator<=(const Mystring &lhs, const Mystring &rhs) {
    Mystring left {-lhs};
    Mystring right {-lhs};
    int cmp = std::strcmp(left.get_str(), right.get_str());
    if (cmp <= 0) {
        return true;
    } else {
        return false;
    }
}

bool operator>(const Mystring &lhs, const Mystring &rhs) {
    Mystring left {-lhs};
    Mystring right {-lhs};
    int cmp = std::strcmp(left.get_str(), right.get_str());
    if (cmp > 0) {
        return true;
    } else {
        return false;
    }
}

bool operator>=(const Mystring &lhs, const Mystring &rhs) {
    Mystring left {-lhs};
    Mystring right {-lhs};
    int cmp = std::strcmp(left.get_str(), right.get_str());
    if (cmp >= 0) {
        return true;
    } else {
        return false;
    }
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    char *buff = new char[lhs.get_length() + rhs.get_length() + 1];
    std::strcpy(buff, lhs.get_str());
    std::strcat(buff, rhs.get_str());
    Mystring new_mystr {buff};
    delete [] buff;
    return new_mystr;
}

Mystring operator*(const Mystring &lhs, int rhs) {
    if (rhs <= 0) {
        return Mystring{""};
    }
    char *buff = new char[lhs.get_length() * rhs + 1];
    for (int i {0}; i < rhs; i++) {
        if (i == 0) {
            std::strcpy(buff, lhs.get_str());
        } else {
            std::strcat(buff, lhs.get_str());
        }
    }
    Mystring new_mystr {buff};
    delete [] buff;
    return new_mystr;
}

Mystring operator*(int lhs, const Mystring &rhs) {
    return rhs * lhs;
}

std::ostream &operator<<(std::ostream &os, const Mystring &obj) {
    os << obj.get_str();
    return os;
}

std::istream &operator>>(std::istream &is, Mystring &obj) {
    std::string input;
    is >> input;
    obj.set_str(input);
    return is;
}