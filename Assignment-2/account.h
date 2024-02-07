#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "customer.h"
#include "transaction.h"
#include <vector>

using namespace std;
//const int N = 1000;
enum Account_type {
                SAVING,CHECKING
};

class Account{

        private:
            Customer* customer;
            double balance;
            int account_number;
            vector<Transaction> transaction_array;
            Account_type account_type;
        public:
            virtual ~Account() {}
            Customer* get_customer();
            double get_balance();
            int get_account_number();
            vector<Transaction> get_transaction();
            Account_type get_account_type();

            void createAccount(Customer* customer,Account_type accountType);
            void set_customer(Customer* customer);
            void set_balance(double balance);
            void set_Transaction(Transaction transaction);
            string to_string();
};
#endif