#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    // test your code here
    std::unique_ptr<Account> savings_account;
    try {
        savings_account = std::make_unique<Savings_Account>("My Account", -100);
    }
    catch (const IllegalBalanceException &ex) {
        std::cout << "Invalid initialization of savings account. Trying again..." << std::endl;
        std::cout << ex.what() << std::endl;
        savings_account = std::make_unique<Savings_Account>("My Account", 0);
    }
    (*savings_account).deposit(100);
    try {
        (*savings_account).withdraw(200);
    }
    catch (const InsufficentFundsException &ex) {
        std::cout << ex.what() << std::endl;
    }
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

