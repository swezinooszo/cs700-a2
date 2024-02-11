/** @file bank.cpp
*   @author Swe Zin Oo
*   @date 8 Feb 2024
*   @brief  The implementation file of "bank.h".
*/

#include <iostream>
#include "bank.h"
#include <vector>
#include "account.h"
#include "saving_account.h"
#include "checking_account.h"
#include "bankUtil.h"
#include "account.h"
#include "Date.h"
#include "senior.h"
#include "adult.h"
#include "student.h"


std::vector<Account*> Bank::get_accounts() const{
    return accounts;
}

Account* Bank::get_account(int accountNumber) const{
    Account* a;
        for (auto account : accounts) {
            if(accountNumber == account->get_account_number()){
                a = account;
            }
        }

    return a;
 }

void Bank::add_account(Account* a){
    // add account to acccount array;
    accounts.push_back(a);
}

double Bank::make_deposit(int accountNumber,double amount,string depositDateString){
    double account_balance;
    Account* a;
    //// retrieve account from account number 
    for (auto account : accounts) {
        if(accountNumber == account->get_account_number()){
             a = account;
        }
    }
    //// *** if account is Saving Account **** ////
    if(a->get_account_type() == SAVING){
        if(!accounts.empty()){
            if (Saving_Account* savingAccount = dynamic_cast<Saving_Account*>(a)){

                //// *** convert dateString to dateFormat **** ////
                Date depositDate = convertStringToDate(depositDateString,'-');

                //// ***** Calculate Interest  *******////
                //// get saving interest rate based on customer type 
                double interest_rate;
                Customer* customer = savingAccount->get_customer();
                Customer_type customerType = customer->get_customer_type();
                if(customerType == SENIOR){
                    Senior* senior = dynamic_cast<Senior*>(customer);
                    interest_rate = senior->get_saving_interest();
                }else if(customerType == ADULT){
                     Adult* adult = dynamic_cast<Adult*>(customer);
                    interest_rate = adult->get_saving_interest();
                }else{
                     Student* student = dynamic_cast<Student*>(customer);
                    interest_rate = student->get_saving_interest();
                }

                //// find transaction's date which hold latest amount to calculate interest
                vector<Transaction> transaction_list = a->get_transaction();

                //// if there is no previous transaction (means 1st transaction), no need to calcuate interest. So, directly add to DEP transaction to transacition list. 
                if(transaction_list.size() == 0){
                         //// ******** make Deposit ********* ////
                        savingAccount-> deposit(amount);

                        // ****** add Deposit transaction to account ************///
                        Transaction transaction(DEP,amount,amount,depositDate);
                        savingAccount->set_Transaction(transaction);
                        account_balance = transaction.get_balance();
                }
                //// if there are transactions, retrieve the date of transaction which hold the last balance.
                //// Then the retrieved date will be 'startDate' and the end date will be the date, which will make deposit(curent argument deposit's date). 
                else{
                    //// finding transation's date which is equal to account balance.
                    Date startDate;
                    double balance = a->get_balance();
                    for(auto transaction : transaction_list){
                        if(transaction.get_balance() == a->get_balance()){ 
                            //// get the date 
                            startDate = transaction.get_date();
                        }
                    }

                    //// ****** add interest to balance ************ ////
                    double interest_amount = savingAccount ->add_interest(startDate,depositDate,balance,interest_rate);
                    // ****** add interest transaction to acount ************///
                    if(interest_amount != 0.00){
                        double interested_balance = savingAccount -> get_balance();
                        Transaction transaction1(INT_CR,interest_amount,interested_balance,depositDate);
                        savingAccount->set_Transaction(transaction1);
                    }

                    //// ******** Make Deposit ********* ////
                    savingAccount-> deposit(amount);

                    // ****** add deposit transaction to account************///
                    double last_balance = savingAccount -> get_balance();
                    Transaction transaction(DEP,amount,last_balance,depositDate);
                    savingAccount->set_Transaction(transaction);
                    account_balance = transaction.get_balance();
                }
            }else{
                
            }
        }

    } 
     //// *** if account is Checking Account **** ////
    else if(a->get_account_type() == CHECKING){
        if(!accounts.empty()){
            if (Checking_Account* checkingAccount = dynamic_cast<Checking_Account*>(a)){
                //// *** convert dateString to dateFormat **** ////
                Date depositDate = convertStringToDate(depositDateString,'-');

                // ***** Calculate Interest *******//
                //// get checking interest rate base on customer type 
                double interest_rate;
                Customer* customer = checkingAccount->get_customer();
                Customer_type customerType = customer->get_customer_type();
                if(customerType == SENIOR){
                    Senior* senior = dynamic_cast<Senior*>(customer);
                    interest_rate = senior->get_checking_interest();
                }else if(customerType == ADULT){
                     Adult* adult = dynamic_cast<Adult*>(customer);
                    interest_rate = adult->get_checking_interest();
                }else{
                     Student* student = dynamic_cast<Student*>(customer);
                    interest_rate = student->get_checking_interest();
                }

                 //// find transaction's date which hold latest amount to calculate interest
                vector<Transaction> transaction_list = a->get_transaction();

                //// if there is no previous transaction (means 1st transaction), no need to calcuate interest. So, directly add to DEP transaction to transacition list. 
                if(transaction_list.size() == 0){
                     //// ******** make deposit ********* ////
                    checkingAccount-> deposit(amount);
                    ////****** add Deposit transaction ************////
                    Transaction transaction(DEP,amount,amount,depositDate);
                    checkingAccount->set_Transaction(transaction);
                    account_balance = transaction.get_balance();
                }
                //// if there are transactions, retrieve the date of transaction which hold the last balance
                //// Then the retrieved transaction date will be 'startDate' and the end date will be the date, which will make deposit(current argument deposit'date). 
                else{
                    //// finding transation's date which is equal to account balance.
                    Date startDate;
                    double balance = a->get_balance();
                    for(auto transaction : transaction_list){
                        if(transaction.get_balance() == a->get_balance()){ 
                            //// get the date 
                            startDate = transaction.get_date();
                        }
                    }

                    // ****** add interest to balance ************///
                    double interest_amount = checkingAccount ->add_interest(startDate,depositDate,balance,interest_rate);
                    // ****** add interest transaction to account ************///
                    if(interest_amount != 0.00){
                        double interested_balance = checkingAccount -> get_balance();
                        Transaction transaction1(INT_CR,interest_amount,interested_balance,depositDate);
                        checkingAccount->set_Transaction(transaction1);
                    }

                    //// ******** Make Deposit ********* ////
                    checkingAccount-> deposit(amount);

                    // ****** add deposit transaction to account ************///
                    double last_balance = checkingAccount -> get_balance();
                    Transaction transaction(DEP,amount,last_balance,depositDate);
                    checkingAccount->set_Transaction(transaction);
                    account_balance = transaction.get_balance();
                }

            }else{
            }
        }
    }
    
    return account_balance;
}

bool Bank::check_withdrawable_amount_or_not(int accountNumber,double withdrawAmount,string withdrawDateString){
    bool isChargedOverDraftPenalty;
    //// retrieve account from account number 
    Account* a;
    for (auto account : accounts) {
        if(accountNumber == account->get_account_number()){
             a = account;
        }
    }
    //// *** if account is Saving Account **** ////
     if(a->get_account_type() == SAVING){
        if(!accounts.empty()){
            if (Saving_Account* savingAccount = dynamic_cast<Saving_Account*>(a)){
                 //// *** convert withdrawDateString to dateFormat **** ////
                Date withdrawDate = convertStringToDate(withdrawDateString,'-');
                
                 //// ****  Overdraft Penalty ***** ////
                double totalAmount = savingAccount -> get_balance();
                 //// if withdrawl amount exceed than balance, then charge overdraft penalty.
                if(totalAmount-withdrawAmount < 0){
                    //// select overdraft penalty base on customer type
                    double overdraft_penalty_amount;
                    Customer* customer = savingAccount->get_customer();
                    Customer_type customerType = customer->get_customer_type();
                    if(customerType == SENIOR){
                        Senior* senior = dynamic_cast<Senior*>(customer);
                        overdraft_penalty_amount = senior->get_overdraft_penalty_charge();
                    }else if(customerType == ADULT){
                        Adult* adult = dynamic_cast<Adult*>(customer);
                        overdraft_penalty_amount = adult->get_overdraft_penalty_charge();
                    }else{
                        Student* student = dynamic_cast<Student*>(customer);
                        overdraft_penalty_amount = student->get_overdraft_penalty_charge();
                    } 

                    //// ***  Charge Overdraft Penalty **** //// 
                    savingAccount->charge_overdraft_penalty(overdraft_penalty_amount);

                    //// ****** add Overdraft Penalty transaction to account ************ ////
                    double last_balance = savingAccount -> get_balance();
                    Transaction transaction2(OD_PEN,overdraft_penalty_amount,last_balance,withdrawDate);
                    savingAccount->set_Transaction(transaction2);
                    isChargedOverDraftPenalty = true;
                }else{
                    isChargedOverDraftPenalty = false;
                }
            }
        } 
     }
      //// *** if account is Checking Account **** ////
      else if(a->get_account_type() == CHECKING){
        if(!accounts.empty()){
            if (Checking_Account* checkingAccount = dynamic_cast<Checking_Account*>(a)){
                 //// *** convert withdrawDateString to dateFormat **** ////
                Date withdrawDate = convertStringToDate(withdrawDateString,'-');
                
                //// ***  Overdraft Penalty **** ////
                double totalAmount = checkingAccount -> get_balance();
                //// if withdrawl amount exceed than balance, then charge overdraft penalty.
                if(totalAmount-withdrawAmount < 0){
                    //// select overdraft penalty base on customer type
                    double overdraft_penalty_amount;
                    Customer* customer = checkingAccount->get_customer();
                    Customer_type customerType = customer->get_customer_type();
                    if(customerType == SENIOR){
                        Senior* senior = dynamic_cast<Senior*>(customer);
                        overdraft_penalty_amount = senior->get_overdraft_penalty_charge();
                    }else if(customerType == ADULT){
                        Adult* adult = dynamic_cast<Adult*>(customer);
                        overdraft_penalty_amount = adult->get_overdraft_penalty_charge();
                    }else{
                        Student* student = dynamic_cast<Student*>(customer);
                        overdraft_penalty_amount = student->get_overdraft_penalty_charge();
                    } 

                    //// ***  Charge Overdraft Penalty **** //// 
                    checkingAccount->charge_overdraft_penalty(overdraft_penalty_amount);

                    // ****** add Overdraft Penalty transaction to account ************///
                    double last_balance = checkingAccount -> get_balance();
                    Transaction transaction2(OD_PEN,overdraft_penalty_amount,last_balance,withdrawDate);
                    checkingAccount->set_Transaction(transaction2);
                    isChargedOverDraftPenalty = true;
                }else{
                    isChargedOverDraftPenalty = false;
                }
                
            }
        }
      }       
    return isChargedOverDraftPenalty;
}


double Bank::make_withdrawl(int accountNumber,double withdrawAmount,string withdrawDateString){
    double account_balance;
    //// retrieve account from account number 
    Account* a;
    for (auto account : accounts) {
        if(accountNumber == account->get_account_number()){
             a = account;
        }
    }
    //// *** if account is Saving Account **** ////
     if(a->get_account_type() == SAVING){
        if(!accounts.empty()){
            if (Saving_Account* savingAccount = dynamic_cast<Saving_Account*>(a)){
               
                //// *** convert withdrawDateString to dateFormat ****////
                Date withdrawDate = convertStringToDate(withdrawDateString,'-');

                //// ***** Calculate Interest *******////
                ////  get saving interest rate base on customer type
                double interest_rate;
                Customer* customer = savingAccount->get_customer();
                Customer_type customerType = customer->get_customer_type();
                if(customerType == SENIOR){
                    Senior* senior = dynamic_cast<Senior*>(customer);
                    interest_rate = senior->get_saving_interest();
                }else if(customerType == ADULT){
                    Adult* adult = dynamic_cast<Adult*>(customer);
                    interest_rate = adult->get_saving_interest();
                }else{
                    Student* student = dynamic_cast<Student*>(customer);
                    interest_rate = student->get_saving_interest();
                }
     
                //// retrieve transaction's date which is equal to account's balance
                //// Then the retrieved transaction date will be 'startDate' and the end date will be the date, which will make withdrawl(current argument withdrawl'date). 
                vector<Transaction> transaction_list = a->get_transaction();
                Date startDate;
                double balance = a->get_balance();
                for(auto transaction : transaction_list){
                    if(transaction.get_balance() == a->get_balance()){
                        //// get the date
                        startDate = transaction.get_date();
                    }
                }

                 // ****** add interest to balance ************///
                double interest_amount = savingAccount ->add_interest(startDate,withdrawDate,balance,interest_rate);
                 // ****** add interest transaction to account ************///
                 if(interest_amount != 0.00){
                    double interested_balance = savingAccount -> get_balance();
                    Transaction transaction1(INT_CR,interest_amount,interested_balance,withdrawDate);
                    savingAccount->set_Transaction(transaction1);
                 }

                //// ******** Make Withdrawl ********* ////
                savingAccount -> withdrawl(withdrawAmount);

                // ****** add withdrawl transaction to account ************///
                double last_balance = savingAccount -> get_balance();
                Transaction transaction2(WD,withdrawAmount,last_balance,withdrawDate);
                savingAccount->set_Transaction(transaction2);
                account_balance = transaction2.get_balance();

            }
        }
    }  
    //// *** if account is Checking Account **** ////
    else if(a->get_account_type() == CHECKING){
        if(!accounts.empty()){
            if (Checking_Account* checkingAccount = dynamic_cast<Checking_Account*>(a)){
                //// *** convert withdrawDateString to dateFormat **** ////
                Date withdrawDate = convertStringToDate(withdrawDateString,'-');

                //// ***** Calculate Interest ******* ////
                //// get checking interest rate and check charge base on customer type
                double interest_rate;
                double check_charge_cents;
                Customer* customer = checkingAccount->get_customer();
                Customer_type customerType = customer->get_customer_type();
                if(customerType == SENIOR){
                    Senior* senior = dynamic_cast<Senior*>(customer);
                    interest_rate = senior->get_checking_interest();
                    check_charge_cents = senior->get_check_charge();
                }else if(customerType == ADULT){
                    Adult* adult = dynamic_cast<Adult*>(customer);
                    interest_rate = adult->get_checking_interest();
                    check_charge_cents = adult->get_check_charge();
                }else{
                     Student* student = dynamic_cast<Student*>(customer);
                     interest_rate = student->get_checking_interest();
                     check_charge_cents = student->get_check_charge();
                }
     
                //// retrieve transaction's date which is equal to account's balance
                //// Then the retrieved transaction date will be 'startDate' and the end date will be the date, which will make withdrawl(current argument withdrawl'date). 
                vector<Transaction> transaction_list = a->get_transaction();
                Date startDate;
                double balance = a->get_balance();
                for(auto transaction : transaction_list){
                    if(transaction.get_balance() == a->get_balance()){
                        //// get the date
                        startDate = transaction.get_date();
                    }
                }

                //// ****** add interest to balance ************////
                double interest_amount = checkingAccount ->add_interest(startDate,withdrawDate,balance,interest_rate);
                 //// ****** add interest transaction to account ************////
                  if(interest_amount != 0.00){
                    double interested_balance = checkingAccount -> get_balance();
                    Transaction transaction1(INT_CR,interest_amount,interested_balance,withdrawDate);
                    checkingAccount->set_Transaction(transaction1);
                  }


                //// ******** Make Withdrawl ********* ////
                checkingAccount -> withdrawl(withdrawAmount);
                // ****** add withdrawl transaction to account ************///
                double last_balance = checkingAccount -> get_balance();
                Transaction transaction2(WD,withdrawAmount,last_balance,withdrawDate);
                checkingAccount->set_Transaction(transaction2);

                //// *********** Checking Charge ************////
                checkingAccount -> deduct_check_charge(check_charge_cents);
                //// ****** add check charge transaction to account ************////
                double lastest_balance = checkingAccount -> get_balance();
                Transaction transaction3(CHKCHG,check_charge_cents,lastest_balance,withdrawDate);
                checkingAccount->set_Transaction(transaction3);
                account_balance = transaction3.get_balance();

            }else{
                
            }
        }
      
    }
    return account_balance;

}
