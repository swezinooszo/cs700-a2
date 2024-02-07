#ifndef BANK_H
#define BANK_H
#include "account.h"
#include <vector>
#include "saving_account.h"
class Bank{
    private:
           std::vector<Account*> accounts;
    public:
        virtual ~Bank() {}
        void add_account(Account* account);
        Account* get_account(int accountNumber);
        std::vector<Account*> get_accounts();
        double make_deposit(int accountNumber,double amount,string date);
        double make_withdrawl(int accountNumber,double amount,string date);
        double check_withdrawable_amount_or_not(int accountNumber,double amount,string date);
      
    
        
};
#endif