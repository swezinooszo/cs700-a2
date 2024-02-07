#include "checking_account.h"
#include "bankUtil.h"

 void Checking_Account::deposit(double amount){
    cout << "checking deposit " << amount << "getbalance "<< get_balance();
    double balance = get_balance() + amount;
    set_balance(balance);
 }
void Checking_Account::withdrawl(double amount){
    double balance = get_balance() - amount;
    set_balance(balance);
}

//calculate interest base on start date, enddate, balance
double Checking_Account::add_interest(Date startDate,Date endDate,double amount,double interest_rate){
  cout << "call add_interest function startDate "<< startDate <<" endDate "<< endDate << " amount "<<amount <<" interest_rate "<<interest_rate << endl;

   // Calculate the day count for each date
    int startDayCount = calculateDayCount(startDate);
    int endDayCount = calculateDayCount(endDate);
    // Calculate the difference in days
    int daysDifference = endDate - startDate;

    double interested_amount = calculateInterest(amount, interest_rate, daysDifference);
    double rounded_interested_amount = roundToTwoDecimalPlaces(interested_amount);
    cout << "calculated interest "<< rounded_interested_amount << " amount "<<amount<<endl;
    double balance = amount + rounded_interested_amount;
    set_balance(balance);
    return rounded_interested_amount;
}
void Checking_Account::deduct_check_charge(double check_charge){
    double balance = get_balance() - check_charge;
    set_balance(balance);
}
void Checking_Account::charge_overdraft_penalty(double penalty_amount){
    double balance = get_balance() - penalty_amount;
    set_balance(balance);
}