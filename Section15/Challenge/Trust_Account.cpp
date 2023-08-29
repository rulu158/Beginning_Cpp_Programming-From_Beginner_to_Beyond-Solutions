#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance,
                double int_rate, int max_withdrawals,
                double max_amount_withdrawable_over_total)
        : Savings_Account(name, balance, int_rate), num_withdrawals_left{max_withdrawals}, max_amount_withdrawable_over_total {max_amount_withdrawable_over_total} {

}

bool Trust_Account::deposit(double amount) {
    if (amount >= 5000.0) {
        amount += 50;
    }
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    if (amount > balance * max_amount_withdrawable_over_total / 100
            || num_withdrawals_left <= 0) {
        return false;
    }
    if (Savings_Account::withdraw(amount)) {
        num_withdrawals_left--;
        return true;
    } else {
        return false;
    }
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: "
        << account.name
        << ": "
        << account.balance
        << ", "
        << account.int_rate
        << "%, withdrawals left: "
        << account.num_withdrawals_left
        << ", max_per_withdrawal: "
        << account.max_amount_withdrawable_over_total
        << "%]";
    return os;
}