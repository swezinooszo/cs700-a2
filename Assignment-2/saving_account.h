#ifndef SAVING_ACCOUNT_H
#define SAVING_ACCOUNT_H
#include "account.h"
#include "transaction.h"

class Saving_Account: public Account{

        public:
            void deposit(double amount);
            void withdrawl(double amount);
            double add_interest(Date startDate,Date endDate,double amount,double interest_rate);
            void charge_overdraft_penalty(double amount);
};
#endif