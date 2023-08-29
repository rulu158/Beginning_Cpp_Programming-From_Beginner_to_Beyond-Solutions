#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include "Savings_Account.h"


class Checking_Account : public Savings_Account
{
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double def_withdrawal_fee = 1.50;
protected:
    const double withdrawal_fee;
public:
    Checking_Account(std::string name = def_name, double balance = def_balance,
            double int_rate = def_int_rate, double withdrawal_fee = def_withdrawal_fee);
    bool withdraw(double amount);
};

#endif // _CHECKING_ACCOUNT_H_