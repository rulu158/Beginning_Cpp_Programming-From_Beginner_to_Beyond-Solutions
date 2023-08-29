#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance, double int_rate, double withdrawal_fee)
        : Savings_Account(name, balance, int_rate), withdrawal_fee{withdrawal_fee} {
    
}

bool Checking_Account::withdraw(double amount) {
    double amount_plus_fee {amount + withdrawal_fee};
    return Savings_Account::withdraw(amount_plus_fee);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%, " << account.withdrawal_fee << "$]";
    return os;
}