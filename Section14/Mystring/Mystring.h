#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>
#include <string>

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &obj);
    friend std::istream &operator>>(std::istream &is, Mystring &obj);
private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                            // No-args contstructor
    Mystring(const char *s);                         // Overloaded contstructor              
    Mystring(std::string s);                        // Overloaded constructor
    Mystring(const Mystring &source);        // Copy constructor
    Mystring(Mystring &&source);            // Move constructor
    ~Mystring();                                          // Destructor
    void display() const;
    int get_length() const;                           // getters
    const char *get_str() const;
    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);
    Mystring operator-() const;
    Mystring operator+(const Mystring &rhs) const;
    bool operator==(const Mystring &rhs) const;
    bool operator!=(const Mystring &rhs) const;
};

#endif // _MYSTRING_H_
