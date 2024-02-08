/** @file bank.h
*   @author Swe Zin Oo
*   @date 8 Feb 2024
*/

#ifndef BANK_H
#define BANK_H
#include "account.h"
#include <vector>
#include "saving_account.h"

/** Banks is a class which holds the information of customers' accounts. It also have include main operations such as making deposit and withdrawl */
class Bank{
    private:
        // Data Fields.
        /** The array of accounts */
        std::vector<Account*> accounts;
    public:
        // virtual destructor
        virtual ~Bank() {}

        // Accessor Functions
        /** Gets the accounts
         * @return the accounts as a vector array
        */
        std::vector<Account*> get_accounts();

        // Other Functions
         /** Gets an account based on account number
         * @param accountNumber the account number
         * @return an account as a pointer object
        */
         Account* get_account(int accountNumber);
        /** Add an account to the bank
         * @param account an account pointer object
        */
        void add_account(Account* account);
        /** make deposit to the bank
         * @param accountNumber the account number to be deposited
         * @param amount the amount to be deposited
         * @param date the date to be deposited
         * @return the balance of account after deposited as a double value
        */
        double make_deposit(int accountNumber,double amount,string date);
        /** make withdrawl from the bank
         * @param accountNumber the account number to be withdrawn
         * @param amount the amount to be withdrawn
         * @param date the withdrawl date
         * @return the balance of account after withdrawn as a double value
        */
        double make_withdrawl(int accountNumber,double amount,string date);
        /** determine whether the provided amount is withdrawable from the account. 
         * This function is always called before customer make withdrawl.
         * If there is no sufficient fund in the account, charge overdraft penalty to the acount.
         * @param accountNumber the account number to be withdrawn
         * @param amount the amount to be withdrawn
         * @param date the withdrawl date
         * @return the boolean value return true, if overdraft penalty is charged. unless, it returns false.
        */
        bool check_withdrawable_amount_or_not(int accountNumber,double amount,string date);
      
    
        
};
#endif