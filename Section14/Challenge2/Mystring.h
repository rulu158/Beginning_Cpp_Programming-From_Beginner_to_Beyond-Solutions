#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>
#include <string>

class Mystring
{
private:
    char *str;
public:
    Mystring();                         // no args
    Mystring(const char *s);            // char *
    Mystring(std::string &s);           // string 
    Mystring(const Mystring &source);   // copy
    Mystring(Mystring &&source);        // move
    ~Mystring();                        // destructor

    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);
    Mystring &operator+=(const Mystring &rhs);
    Mystring &operator*=(int rhs);

    const char *get_str() const;
    void set_str(const char *s);
    void set_str(std::string &s);

    int get_length() const;

    void display() const;
};

Mystring operator+(const Mystring &obj);
Mystring operator-(const Mystring &obj);
Mystring &operator++(Mystring &obj);
Mystring operator++(Mystring &obj, int);
Mystring &operator--(Mystring &obj);
Mystring operator--(Mystring &obj, int);

bool operator==(const Mystring &lhs, const Mystring &rhs);
bool operator!=(const Mystring &lhs, const Mystring &rhs);
bool operator<(const Mystring &lhs, const Mystring &rhs);
bool operator<=(const Mystring &lhs, const Mystring &rhs);
bool operator>(const Mystring &lhs, const Mystring &rhs);
bool operator>=(const Mystring &lhs, const Mystring &rhs);

Mystring operator+(const Mystring &lhs, const Mystring &rhs);
Mystring operator*(const Mystring &lhs, int rhs);
Mystring operator*(int lhs, const Mystring &rhs);

std::ostream &operator<<(std::ostream &os, const Mystring &obj);
std::istream &operator>>(std::istream &is, Mystring &obj);

#endif // _MYSTRING_H_
