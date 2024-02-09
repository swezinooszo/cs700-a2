/** @file bank.h
*   @author Swe Zin Oo
*   @date 8 Feb 2024
*/

#ifndef BANK_H
#define BANK_H
#include "account.h"
#include <vector>
#include "saving_account.h"

/** Banks is a class which holds the information of customers and their accounts. It can be considered as a secondary entry point of the program. 
 * The implementation details of adding accounts, retrieving accounts, making deposits, applying interest, processing withdrawals and 
 * checking for insufficient funds in the account, are all written here.
*/
class Bank{
    private:
        // Data Fields.
        /** The array of accounts */
        std::vector<Account*> accounts;
    public:
        // virtual destructor
        virtual ~Bank() {}

        // Accessor Functions
        /** Gets the accounts from the bank
         * @return the accounts as a vector array
        */
        std::vector<Account*> get_accounts() const;

        // Other Functions
         /** Gets an account from the bank based on the account number
         * @param accountNumber the account number
         * @return an account as a pointer object
        */
         Account* get_account(int accountNumber) const;
        /** Add an account to the bank
         * @param account an account pointer object
        */
        void add_account(Account* account);
        /** make deposit to the bank. Each time a customer makes a deposit, the interest amount is calculated according to the annual rate and the number of days
         *  the account's balance has been held. Subsequently, the interest amount is added to the balance of the account.
         * @param accountNumber the account number to be deposited
         * @param amount the amount to be deposited
         * @param date the date to be deposited
         * @return the balance of account after deposited as a double value
        */
        double make_deposit(int accountNumber,double amount,string date);
        /** make withdrawl from the bank.Each time a customer makes a withdrawl, the interest amount is calculated according to the annual rate and the number of days
         *  the account's balance has been held. This interest amount is then added to the account's balance. Additionally, if the account is a checking account, 
         *  a checking charge is calculated and deducted from the account's balance.
         * @param accountNumber the account number to be withdrawn
         * @param amount the amount to be withdrawn
         * @param date the withdrawl date
         * @return the balance of account after withdrawn as a double value
        */
        double make_withdrawl(int accountNumber,double amount,string date);
        /** determine whether the provided amount is withdrawable from the account. 
         * This function is always called before a customer make a withdrawl.
         * If there are insufficient funds in the account, an overdraft penalty is charged to the account, and 
         * the function returns a boolean value of true. If there are enough funds in the account, an overdraft penalty 
         * is not charged, and the function returns a boolean value of false.
         * @param accountNumber the account number to be withdrawn
         * @param amount the amount to be withdrawn
         * @param date the withdrawl date
         * @return the boolean value return true, if overdraft penalty is charged. unless, it returns false.
        */
        bool check_withdrawable_amount_or_not(int accountNumber,double amount,string date);
      
    
        
};
#endif