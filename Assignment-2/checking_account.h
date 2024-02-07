#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H
#include "account.h"
#include "transaction.h"

class Checking_Account: public Account{

        public:
            void deposit(double amount);
            void withdrawl(double amount);
            double add_interest(Date startDate,Date endDate,double amount,double interest_rate);
            void deduct_check_charge(double check_charge);
            void charge_overdraft_penalty(double amount);
            
};

#endif