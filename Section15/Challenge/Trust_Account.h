#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Savings_Account.h"

class Trust_Account : public Savings_Account
{
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr const char *def_name {"Unnamed Trust Account"};
    static constexpr const double def_balance {0.0};
    static constexpr const double def_int_rate {0.0};
    static constexpr int def_max_withdrawals {3};
    static constexpr double def_max_amount_withdrawable_over_total {20.0};
protected:
    int num_withdrawals_left;
    double max_amount_withdrawable_over_total;
public:
    Trust_Account(std::string name = def_name, double balance = def_balance,
            double int_rate = def_int_rate, int max_withdrawals = def_max_withdrawals,
            double max_amount_withdrawable_over_total = def_max_amount_withdrawable_over_total);
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif // _TRUST_ACCOUNT_H_