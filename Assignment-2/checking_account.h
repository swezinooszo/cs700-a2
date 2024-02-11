/** @file checking_account.h
*   @author Swe Zin Oo
*   @date 8 Feb 2024
*/

#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H
#include "account.h"
#include "transaction.h"

/** Checking_Account is a class which extends the Account class. In another words, it's a child class of Account parent class. 
 * Checking_Account class will inherit all member varialbes and functions of the Account class when creating an object.
*/
class Checking_Account: public Account{

        public:
            // Other Functions
            /** make deposit to checking account
             * @param amount the amount to be deposited
            */
            void deposit(double amount);
            /** make withdrawl to checking account
             * @param amount the amount to be withdrawn
            */
            void withdrawl(double amount);
            /** add interest to the checking account
             * @param startDate the start date to be calculated for interest
             * @param endDate the end date to be calculated for interest
             * @param amount the amount to be calculated for interest
             * @param interest_rate the interest rate
            */
            double add_interest(Date startDate,Date endDate,double amount,double interest_rate);
            /** deduct checking charge from the checking account. (Everytime the customer withdraw money from the checking account, 
             * there is a checking charge for that withdrawl.)
             * @param check_charge the amount of checking charge
            */
            void deduct_check_charge(double check_charge);
            /** deduct overdraft penalty charge from the checking account.
             * @param amount the amount to be charged for overdraft penalty
            */
            void charge_overdraft_penalty(double amount);
            
};

#endif