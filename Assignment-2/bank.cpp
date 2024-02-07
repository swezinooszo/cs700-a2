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


void Bank::add_account(Account* a){
    // add account to acccount array;
    accounts.push_back(a);
}

std::vector<Account*> Bank::get_accounts(){
    // get account from account array;
    return accounts;
}

Account* Bank::get_account(int accountNumber){
    Account* a;
        for (auto account : accounts) {
            if(accountNumber == account->get_account_number()){
                a = account;
                cout << "acc number found balance "<< a->get_balance() << endl;
            }
        }

    return a;
 }

double Bank::make_deposit(int accountNumber,double amount,string depositDateString){
    cout << "aBank::make_deposit function size "<< accounts.size() << endl;
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
        cout << "acc type is saving" << endl;
        if(!accounts.empty()){
            if (Saving_Account* savingAccount = dynamic_cast<Saving_Account*>(a)){
                cout << "get saving acc" << endl;

                //// *** convert dateString to dateFormat **** ////
                Date depositDate = convertStringToDate(depositDateString,'-');

                //// ***** Calculate Interest  *******////
                //// get saving interest rate base on customer type 
                double interest_rate;
                Customer* customer = savingAccount->get_customer();
                Customer_type customerType = customer->get_customer_type();
                if(customerType == SENIOR){
                    Senior* senior = dynamic_cast<Senior*>(customer);
                    interest_rate = senior->SAVINGS_INTEREST;
                }else if(customerType == ADULT){
                     cout << "Adult saving interest" << endl;
                     Adult* adult = dynamic_cast<Adult*>(customer);
                    interest_rate = adult->SAVINGS_INTEREST;
                }else{
                     Student* student = dynamic_cast<Student*>(customer);
                    interest_rate = student->SAVINGS_INTEREST;
                }

                //// find transaction's date which hold latest amount to calculate interest
                vector<Transaction> transaction_list = a->get_transaction();

                //// if there is no previous transaction, no need to calcuate interest. So, directly add to DEP transaction to transacition list. 
                if(transaction_list.size() == 0){
                         /// ******** make Deposit *********/
                        savingAccount-> deposit(amount);

                        // ****** add Deposit transaction ************///
                        Transaction transaction(DEP,amount,amount,depositDate);
                        savingAccount->set_Transaction(transaction);
                        account_balance = transaction.get_balance();
                }
                //// if there are transactions, retrieve the date of transaction which hold the last balance to calculate interest 
                //// Then the retrieved transaction date will be 'startDate' and the date which made deposit will be 'endDate' in interest calculation. 
                else{
                    //// finding transation's date which is equal to account balance.
                    Date startDate;
                    int balance = a->get_balance();
                    for(auto transaction : transaction_list){
                        cout << "transaction balance "<< transaction.get_balance() << " acc balance " << a->get_balance()<< endl ;
                        if(transaction.get_balance() == a->get_balance()){ 
                            cout << " lastly, get transaction balance "<< transaction.get_balance() << endl;
                            //// get the date 
                            startDate = transaction.get_date();
                        }
                    }

                    //// ****** add interest to balance ************ ////
                    double interest_amount = savingAccount ->add_interest(startDate,depositDate,balance,interest_rate);
                    // ****** add interest transaction ************///
                    if(interest_amount != 0.00){
                        double interested_balance = savingAccount -> get_balance();
                        Transaction transaction1(INT_CR,interest_amount,interested_balance,depositDate);
                        savingAccount->set_Transaction(transaction1);
                    }

                    /// ******** Make Deposit *********/
                    savingAccount-> deposit(amount);

                    // ****** add deposit transaction ************///
                    double last_balance = savingAccount -> get_balance();
                    cout << "get saving acc format date " << depositDate;
                    Transaction transaction(DEP,amount,last_balance,depositDate);
                    savingAccount->set_Transaction(transaction);
                    account_balance = transaction.get_balance();
                }
            }else{
                 cout << "not get saving acc" << endl;
            }
        }

    } 
     //// *** if account is Checking Account **** ////
    else if(a->get_account_type() == CHECKING){
        cout << "acc type is checking" << endl;
        if(!accounts.empty()){
            if (Checking_Account* checkingAccount = dynamic_cast<Checking_Account*>(a)){
                cout << "get checking acc" << endl;
                //// *** convert dateString to dateFormat **** ////
                Date depositDate = convertStringToDate(depositDateString,'-');

                // ***** Calculate Interest *******//
                //// get checking interest rate base on customer type 
                double interest_rate;
                Customer* customer = checkingAccount->get_customer();
                Customer_type customerType = customer->get_customer_type();
                if(customerType == SENIOR){
                    Senior* senior = dynamic_cast<Senior*>(customer);
                    interest_rate = senior->CHECKING_INTEREST;
                }else if(customerType == ADULT){
                     Adult* adult = dynamic_cast<Adult*>(customer);
                    interest_rate = adult->CHECKING_INTEREST;
                }else{
                     Student* student = dynamic_cast<Student*>(customer);
                    interest_rate = student->CHECKING_INTEREST;
                }

                 //// find transaction's date which hold latest amount to calculate interest
                vector<Transaction> transaction_list = a->get_transaction();

                //// if there is no previous transaction, no need to calcuate interest. So, directly add to DEP transaction to transacition list. 
                if(transaction_list.size() == 0){
                     //// ******** make deposit *********////
                    checkingAccount-> deposit(amount);
                    ////****** add Deposit transaction ************////
                    Transaction transaction(DEP,amount,amount,depositDate);
                    checkingAccount->set_Transaction(transaction);
                    account_balance = transaction.get_balance();
                }
                //// if there are transactions, retrieve the date of transaction which hold the last balance to calculate interest 
                //// Then the retrieved transaction date will be 'startDate' and the date which made deposit will be 'endDate' in interest calculation. 
                else{
                    //// finding transation's date which is equal to account balance.
                    Date startDate;
                    int balance = a->get_balance();
                    for(auto transaction : transaction_list){
                        cout << "transaction balance "<< transaction.get_balance() << " acc balance " << a->get_balance()<< endl ;
                        if(transaction.get_balance() == a->get_balance()){ 
                            cout << " lastly, get transaction balance "<< transaction.get_balance() << endl;
                            //// get the date 
                            startDate = transaction.get_date();
                        }
                    }

                    // ****** add interest to balance ************///
                    double interest_amount = checkingAccount ->add_interest(startDate,depositDate,balance,interest_rate);
                    // ****** add interest transaction ************///
                    if(interest_amount != 0.00){
                        double interested_balance = checkingAccount -> get_balance();
                        Transaction transaction1(INT_CR,interest_amount,interested_balance,depositDate);
                        checkingAccount->set_Transaction(transaction1);
                    }

                    //// ******** Make Deposit *********////
                    checkingAccount-> deposit(amount);

                    // ****** add deposit transaction ************///
                    double last_balance = checkingAccount -> get_balance();
                    Transaction transaction(DEP,amount,last_balance,depositDate);
                    checkingAccount->set_Transaction(transaction);
                    account_balance = transaction.get_balance();
                }

            }else{
                 cout << "not get checking acc" << endl;
            }
        }
    }
    
    return account_balance;
}

double Bank::check_withdrawable_amount_or_not(int accountNumber,double withdrawAmount,string withdrawDateString){
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
        cout << "acc type is saving" << endl;
        if(!accounts.empty()){
            if (Saving_Account* savingAccount = dynamic_cast<Saving_Account*>(a)){
                 //// *** convert withdrawDateString to dateFormat **** ////
                Date withdrawDate = convertStringToDate(withdrawDateString,'-');
                
                 //// ****  Overdraft Penalty ***** ////
                int totalAmount = savingAccount -> get_balance();
                 //// if withdrawl amount exceed than balance, then charge overdraft penalty.
                if(totalAmount-withdrawAmount < 0){
                    //// select overdraft penalty base on customer type
                    double overdraft_penalty_amount;
                    Customer* customer = savingAccount->get_customer();
                    Customer_type customerType = customer->get_customer_type();
                    if(customerType == SENIOR){
                        Senior* senior = dynamic_cast<Senior*>(customer);
                        overdraft_penalty_amount = senior->OVERDRAFT_PENALTY;
                    }else if(customerType == ADULT){
                        Adult* adult = dynamic_cast<Adult*>(customer);
                        overdraft_penalty_amount = adult->OVERDRAFT_PENALTY;
                    }else{
                        Student* student = dynamic_cast<Student*>(customer);
                        overdraft_penalty_amount = student->OVERDRAFT_PENALTY;
                    } 

                    //// ***  Charge Overdraft Penalty **** //// 
                    savingAccount->charge_overdraft_penalty(overdraft_penalty_amount);

                    //// ****** add Overdraft Penalty transaction ************ ////
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
                int totalAmount = checkingAccount -> get_balance();
                //// if withdrawl amount exceed than balance, then charge overdraft penalty.
                if(totalAmount-withdrawAmount < 0){
                    //// select overdraft penalty base on customer type
                    double overdraft_penalty_amount;
                    Customer* customer = checkingAccount->get_customer();
                    Customer_type customerType = customer->get_customer_type();
                    if(customerType == SENIOR){
                        Senior* senior = dynamic_cast<Senior*>(customer);
                        overdraft_penalty_amount = senior->OVERDRAFT_PENALTY;
                    }else if(customerType == ADULT){
                        Adult* adult = dynamic_cast<Adult*>(customer);
                        overdraft_penalty_amount = adult->OVERDRAFT_PENALTY;
                    }else{
                        Student* student = dynamic_cast<Student*>(customer);
                        overdraft_penalty_amount = student->OVERDRAFT_PENALTY;
                    } 

                    //// ***  Charge Overdraft Penalty **** //// 
                    checkingAccount->charge_overdraft_penalty(overdraft_penalty_amount);

                    // ****** add Overdraft Penalty transaction ************///
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
                    interest_rate = senior->SAVINGS_INTEREST;
                }else if(customerType == ADULT){
                    Adult* adult = dynamic_cast<Adult*>(customer);
                    interest_rate = adult->SAVINGS_INTEREST;
                }else{
                    Student* student = dynamic_cast<Student*>(customer);
                    interest_rate = student->SAVINGS_INTEREST;
                }
     
                //// find transaction's date which hold latest amount to calculate interest
                vector<Transaction> transaction_list = a->get_transaction();
                //// find transaction's date which is equal to account balance
                Date startDate;
                int balance = a->get_balance();
                for(auto transaction : transaction_list){
                    cout << "transaction balance "<< transaction.get_balance() << " acc balance " << a->get_balance()<< endl ;
                    if(transaction.get_balance() == a->get_balance()){
                        cout << " lastly, get transaction balance "<< transaction.get_balance() << endl;
                        //// get the date
                        startDate = transaction.get_date();
                    }
                }

                 // ****** add interest to balance ************///
                double interest_amount = savingAccount ->add_interest(startDate,withdrawDate,balance,interest_rate);
                 // ****** add interest transaction ************///
                 if(interest_amount != 0.00){
                    double interested_balance = savingAccount -> get_balance();
                    Transaction transaction1(INT_CR,interest_amount,interested_balance,withdrawDate);
                    savingAccount->set_Transaction(transaction1);
                 }

                /// ******** Make Withdrawl *********/
                savingAccount -> withdrawl(withdrawAmount);

                // ****** add withdrawl transaction ************///
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
                    interest_rate = senior->CHECKING_INTEREST;
                    check_charge_cents = senior->CHECK_CHARGE;
                }else if(customerType == ADULT){
                    Adult* adult = dynamic_cast<Adult*>(customer);
                    interest_rate = adult->CHECKING_INTEREST;
                    check_charge_cents = adult->CHECK_CHARGE;
                }else{
                     Student* student = dynamic_cast<Student*>(customer);
                     interest_rate = student->CHECKING_INTEREST;
                     check_charge_cents = student->CHECK_CHARGE;
                }
     
                //// find transaction's date which hold latest amount to calculate interest
                vector<Transaction> transaction_list = a->get_transaction();
                //// find transaction's date which is equal to account balance
                Date startDate;
                int balance = a->get_balance();
                for(auto transaction : transaction_list){
                    if(transaction.get_balance() == a->get_balance()){
                        //// get the date
                        startDate = transaction.get_date();
                    }
                }

                //// ****** add interest to balance ************////
                double interest_amount = checkingAccount ->add_interest(startDate,withdrawDate,balance,interest_rate);
                 //// ****** add interest transaction ************////
                  if(interest_amount != 0.00){
                    double interested_balance = checkingAccount -> get_balance();
                    Transaction transaction1(INT_CR,interest_amount,interested_balance,withdrawDate);
                    checkingAccount->set_Transaction(transaction1);
                  }


                //// ******** Make Withdrawl *********///
                checkingAccount -> withdrawl(withdrawAmount);
                // ****** add withdrawl transaction ************///
                double last_balance = checkingAccount -> get_balance();
                Transaction transaction2(WD,withdrawAmount,last_balance,withdrawDate);
                checkingAccount->set_Transaction(transaction2);

                //// *********** Checking Charge ************////
                checkingAccount -> deduct_check_charge(check_charge_cents);
                //// ****** add check charge transaction ************////
                double lastest_balance = checkingAccount -> get_balance();
                Transaction transaction3(CHKCHG,check_charge_cents,lastest_balance,withdrawDate);
                checkingAccount->set_Transaction(transaction3);
                account_balance = transaction3.get_balance();

            }else{
                 cout << "not get checking acc" << endl;
            }
        }
      
    }
    return account_balance;

}
