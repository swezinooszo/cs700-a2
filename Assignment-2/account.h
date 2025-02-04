/** @file account.h
*   @author Swe Zin Oo
*   @date 8 Feb 2024
*/


#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "customer.h"
#include "transaction.h"
#include <vector>

using namespace std;
/** Account_type is an enum class which represents different types of account*/
enum Account_type {
            // Data Fields
            /** SAVING is used for saving account */
            SAVING,
            /** CHECKING is used for checking account */
            CHECKING
};
/** Account is a class which holds the information of a customer, account's details and the transactions */
class Account{

        private:
            // Data Fields
            /** The customer */
            Customer* customer;
            /** The balance */
            double balance;
            /** The account number */
            int account_number;
            /** The transaction arrays */
            vector<Transaction> transaction_array;
             /** The account type */
            Account_type account_type;
        public:
            // virtual destructor
            virtual ~Account() {}
            // Accessor Functions
            /** Gets the customer.
             * @return the customer as an object
            */
            Customer* get_customer() const;
             /** Gets the bank account's balance of the customer.
             * @return the balance as a double value
            */
            double get_balance() const;
             /** Gets the bank account number of the customer.
             * @return the account number as an integer value
            */
            int get_account_number() const;
             /** Gets the transactions which customer made.
             * @return the transactions as an array
            */
            vector<Transaction> get_transaction() const;
             /** Gets the account type.
             * @return an enum Account_type value. 
            */
            Account_type get_account_type() const;

            // Modifier Functions
            /** Sets the customer field.
             * @param customer customer as an object
            */
            void set_customer(Customer* customer);
            /** Sets the balance field.
             * @param balance the amount of balance
            */
            void set_balance(double balance);
            /** Sets the transaction_array field.
             * @param transaction the array of transactions
            */
            void set_Transaction(Transaction transaction);

            // Other Functions
             /** Create an account. The function is called when a customer create saving or checking account.
              * A random number is generated for the account number when creating an account
             * @param customer the customer belong to the account 
             * @param accountType the type of customer 
            */
            void createAccount(Customer* customer,Account_type accountType);
};
#endif