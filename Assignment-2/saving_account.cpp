/** @file saving_account.cpp
*   @author Swe Zin Oo
*   @date 8 Feb 2024
*   @brief The implementation file of "saving_account.h".
*/


#include "saving_account.h"
#include <iostream>
#include "bankUtil.h"
#include "bankUtil.h"

void Saving_Account::deposit(double amount){
   cout << "Saving_Account::deposit" << endl;
   double balance = get_balance() + amount;
   set_balance(balance);
}

void Saving_Account::withdrawl(double amount){
  cout << "call withdrawl function" << endl;
  double balance = get_balance() - amount;
  set_balance(balance);
}
double Saving_Account::add_interest(Date startDate,Date endDate,double amount,double interest_rate){
  cout << "call add_interest function startDate "<< startDate <<" endDate "<< endDate << " amount "<<amount <<" interest_rate "<<interest_rate << endl;

   // Calculate the day count for each date
    int startDayCount = calculateDayCount(startDate);
    int endDayCount = calculateDayCount(endDate);
    // Calculate the difference in days
    int daysDifference = endDayCount - startDayCount;
    cout << "daysDifference "<< daysDifference << endl;
    double interested_amount = calculateInterest(amount, interest_rate, daysDifference);
    double rounded_interested_amount = roundToTwoDecimalPlaces(interested_amount);
    cout << "calculated interest "<< rounded_interested_amount << " amount "<<amount<<endl;
    double balance = amount + rounded_interested_amount;
    set_balance(balance);
    return rounded_interested_amount;
}

void Saving_Account::charge_overdraft_penalty(double penalty_amount){
    double balance = get_balance() - penalty_amount;
    set_balance(balance);
}