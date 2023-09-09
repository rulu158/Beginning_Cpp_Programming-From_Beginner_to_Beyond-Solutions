#ifndef __ILLEGAL_BALANCE_EXCEPTION_H__
#define __ILLEGAL_BALANCE_EXCEPTION_H__
#include <exception>
#include <iostream>

class IllegalBalanceException : public std::exception
{
public:
    IllegalBalanceException() noexcept {}
    ~IllegalBalanceException() {}
    virtual const char *what() const noexcept {
        return "Balance can't be negative.";
    }
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
