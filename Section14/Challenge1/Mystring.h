#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>
#include <string>


class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &obj);
    friend std::istream &operator>>(std::istream &is, Mystring &obj);
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

    Mystring operator+() const;
    Mystring operator-() const;
    Mystring &operator++();
    Mystring operator++(int);
    Mystring &operator--();
    Mystring operator--(int);

    bool operator==(const Mystring &rhs) const;
    bool operator!=(const Mystring &rhs) const;
    bool operator<(const Mystring &rhs) const;
    bool operator<=(const Mystring &rhs) const;
    bool operator>(const Mystring &rhs) const;
    bool operator>=(const Mystring &rhs) const;

    Mystring operator+(const Mystring &m) const;
    Mystring operator*(int rhs) const;

    const char *get_str() const;
    int get_length() const;

    void display() const;
};

#endif // _MYSTRING_H_
