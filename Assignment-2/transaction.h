/** @file Transaction.h
*   @author Swe Zin Oo
*   @date 8 Feb 2024
*/
#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "Date.h"
#include <iostream>
using namespace std;

/** Transaction_type is an enum class which represents different types of transactions */
enum Transaction_type {
    // Data Fields
    /** DEP is used for Deposit transaction */
    DEP, 
    /** INT_CR is used for Interest transaction */
    INT_CR, 
    /** WD is used for Withdrawl transaction */
    WD,
    /** CHKCHG is used for Check Charge transaction */
    CHKCHG,
    /** OD_PEN is used for Overdraft Penalty transaction */
    OD_PEN
};

/** Transaction is a class which stores the all the information of a transaction */
class Transaction{

    private:
        // Data Fields
        /** The transaction type */
        Transaction_type transaction_type;
        /** The amount */
        double amount;
        /** The balance */
        double balance;
        /** The date */
        Date date;

    public:
        //Constructors
        /** Constructs a transaction with given values.
         * @param tranType the transaction type
         * @param amt the amount to be stored in the transaction
         * @param bal the balance of an account to be stored in transaction
         * @param d the transaction date
        */
        Transaction(Transaction_type tranType, double amt, double bal, Date d)
                : transaction_type(tranType), amount(amt), balance(bal), date(d) {
                  
                }
        // Accessor Function
        /** Gets the transaction type
         * @return an enum Transaction_type value. 
        */
        Transaction_type get_transaction_type();  
        /** Gets the amount
         * @return the amount of the transaction
        */      
        double get_amount();
         /** Gets the balance
         * @return the balance in the account at the time of the transaction
        */ 
        double get_balance();
         /** Gets the date
         * @return the transaction date
        */ 
        Date get_date();
         /** Gets the details of transaction as a string
         * @return  a string value which returns all the member variables 
        */ 
        string to_string()  ;
    
};
#endif