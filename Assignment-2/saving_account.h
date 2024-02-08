/** @file saving_account.h
*   @author Swe Zin Oo
*   @date 8 Feb 2024
*/

/** Saving_Account is a class which extends the Account class. In another words, it's a child class of Account parent class. 
 * Saving_Account class will inherit all member varialbes and functions of the Account class when creating an object.
*/
#ifndef SAVING_ACCOUNT_H
#define SAVING_ACCOUNT_H
#include "account.h"
#include "transaction.h"

class Saving_Account: public Account{

        public:
            // Other Functions
            /** make deposit to saving account
             * @param amount the amount to be deposited
            */
            void deposit(double amount);
            /** make withdrawl to saving account
             * @param amount the amount to be withdrawn
            */
            void withdrawl(double amount);
            /** add interest to the saving account
             * @param startDate the start date to be calculated for interest
             * @param endDate the end date to be calculated for interest
             * @param amount the amount to be calculated for interest
             * @param interest_rate the interest rate
            */
            double add_interest(Date startDate,Date endDate,double amount,double interest_rate);
             /** deduct overdraft penalty charge from the saving account.
             * @param amount the amount to be charged for overdraft penalty
            */
            void charge_overdraft_penalty(double amount);
};
#endif