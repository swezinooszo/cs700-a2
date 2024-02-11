/** @file main.cpp
*   @author Swe Zin Oo
*   @date 8 Feb 2024
*   @brief The "main.cpp" file serves as the program entry point. All functions, such as adding accounts, making deposits, making withdrawals, 
*          calculating interests, charging overdraft penalties and checking accounts, originate from this location.
*/
#include <iostream>
#include "adult.h"
#include <string>
#include "adult.h"
#include "senior.h"
#include "student.h"
#include "saving_account.h"
#include "checking_account.h"
#include "account.h"
#include "bank.h"
#include "bankUtil.h"
#include <vector>

using namespace std;

int main(){
    bool isExit;
    Bank bank;

    while (!isExit)
    {
        //// ************* Start Transaction *************////

        //// ************* Select Transaction Type *************////
        int bankTransactiontype;
        cout << "Select: \n0: Add Account \n1: Make Deposit \n2: Make Withdrawal \n3: Check Account \n4: Exit" << endl;
        cin >> bankTransactiontype;  
        
        //// ************* Select '0:Add Bank Account' *************////
        if(bankTransactiontype == 0){

            //// ************* 1. Enter Customer Details *************////
            string name;
            string address;
            int age;
            int phoneNumber;
            cout << "Enter Customer Name ";
            cin >> name;
            cout << "Enter Customer Address ";
            cin >> address;
            cout << "Enter Customer Age ";
            cin >> age;
            cout << "Enter Customer Phone Number ";
            cin >> phoneNumber;

            //// ************* 2. Select 'Customer Type' *************////
            int customerType;
            cout << "Select: \n0: Senior \n1: Adult \n2: Student" << endl;
            cin >> customerType;

                //// ************* Choose Senior  *******************////
                if(customerType == 0){
                    Senior* senior = new Senior();
                    senior->set_name(name);
                    senior->set_address(address);
                    senior->set_age(age);
                    senior->set_telephone_number(phoneNumber);
                    senior->set_customer_type(SENIOR);

                    //// ************* 3. Select 'Account Type' *************////
                    int accountType;
                    cout << "Select: \n0: Checking \n1: Savings" << endl;
                    cin >> accountType;
                    //// ************* Create Checking Account *************////
                    if(accountType == 0){
                        Checking_Account* checking_account = new Checking_Account();
                        Account_type accType = CHECKING;
                        checking_account->createAccount(senior,accType);
                        bank.add_account(checking_account);
                        cout << "Account: " << checking_account->get_account_number() << " Added" ;
                        cout << endl;
                    }
                    //// ************* Create Saving Account *************////
                    else if(accountType == 1){
                        Saving_Account* saving_account = new Saving_Account();
                        Account_type accType = SAVING;
                        saving_account->createAccount(senior,accType);
                        bank.add_account(saving_account);
                        cout << "Account: " << saving_account->get_account_number() << " Added" ;
                        cout << endl;
                    }
                
                }
                //// ************* Choose Adult *************////
                else if(customerType == 1){
                    Adult* adult = new Adult();
                    adult->set_name(name);
                    adult->set_address(address);
                    adult->set_age(age);
                    adult->set_telephone_number(phoneNumber);
                    adult->set_customer_type(ADULT);
                 
                     //// ************* 3. Select 'Account Type' *************////
                    int accountType;
                    cout << "Select: \n0: Checking \n1: Savings" << endl;
                    cin >> accountType;
                    //// ************* Create Checking Account *************////
                    if(accountType == 0){
                        Checking_Account* checking_account = new Checking_Account();
                        Account_type accType = CHECKING;
                        checking_account->createAccount(adult,accType);
                        bank.add_account(checking_account);
                        cout << "Account: " << checking_account->get_account_number() << " Added" ;
                        cout << endl;
                    }
                    //// ************* Create Saving Account  *************////
                    else if(accountType == 1){  
                        Saving_Account* saving_account = new Saving_Account();
                        Account_type accType = SAVING;
                        saving_account->createAccount(adult,accType);
                        bank.add_account(saving_account);
                        cout << "Account: " << saving_account->get_account_number() << " Added" ;
                        cout << endl;
                    }
                
                }
                //// ************* Choose Student  *************////
                else if(customerType == 2){
                
                    Student* student = new Student();
                    student->set_name(name);
                    student->set_address(address);
                    student->set_age(age);
                    student->set_telephone_number(phoneNumber);
                    student->set_customer_type(STUDENT);

                     //// ************* 3. Select 'Account Type' *************////
                    int accountType;
                    cout << "Select: \n0: Checking \n1: Savings" << endl;
                    cin >> accountType;
                    //// ************* Create Checking Account *************////
                    if(accountType == 0){
                        Checking_Account* checking_account = new Checking_Account();
                        Account_type accType = CHECKING;
                        checking_account->createAccount(student,accType);
                        bank.add_account(checking_account);
                        cout << "Account: " << checking_account->get_account_number() << " Added" ;
                        cout << endl;
                    }
                    //// ************* Create Saving Account *************////
                    else if(accountType == 1){
                        Saving_Account* saving_account = new Saving_Account();
                        Account_type accType = SAVING;
                        saving_account->createAccount(student,accType);
                        bank.add_account(saving_account);
                        cout << "Account: " << saving_account->get_account_number() << " Added" ;
                        cout << endl;
                    }
                
                }

        
        } 
        //// ************* Select '1:Make Deposit' *************////
        else if(bankTransactiontype == 1){
            int accountNumber;
            double amount;
            string date;

            cout << "Enter Account Number ";
            cin >> accountNumber;
            cout << "Enter The Amount ";
            cin >> amount;
            cout << "Enter the date yyyy-mm-dd ";
            cin >> date;

            double account_balance = bank.make_deposit(accountNumber,amount,date);
            cout << "Deposit in " << accountNumber << " amount: $" << amount << " on " << date << " new balance: $" << account_balance << endl;

        }
         //// ************* Select '2:Make Withdrawl' *************////
         else if(bankTransactiontype == 2){

            int accountNumber;
            double amount;
            string date;

            cout << "Enter Account Number ";
            cin >> accountNumber;
            cout << "Enter The Amount ";
            cin >> amount;
            cout << "Enter the date yyyy-mm-dd ";
            cin >> date;

            //// Retrieve account first which is equal to entered account number to check whether there are sufficient funds 
            Account* a;
            for (auto account : bank.get_accounts()) {
                if(accountNumber == account->get_account_number()){
                    a = account;
                }
            }
            //// if balance is negative, disallow withdrawing amount and display the message
            if(a->get_balance() <0){
                cout << "The balance from account "<< accountNumber << " is negative "<< a->get_balance() << ". Withdrawal failed." << endl;
            }
            //// if balance is positive, allow withdrawing amount 
            else {
                //// 1. if balance is positive but withdrawl amount is exceed than balance, then overdraft penalty is charged and return 'isChargedOverDraftPenalty' as true 
                bool isChargedOverDraftPenalty = bank.check_withdrawable_amount_or_not(accountNumber,amount,date);
                if(isChargedOverDraftPenalty){
                    cout << "Insufficient funds. Withdrawal failed." << endl;
                    double amount;
                    double balance;
                    vector<Transaction> transaction_list = a->get_transaction();
                    for (auto transaction : transaction_list){
                        if(transaction.get_transaction_type() == OD_PEN){
                            amount = transaction.get_amount();
                            balance = transaction.get_balance();
                        }
                    }
                    cout << "Overdraft Penalty is charged from " << accountNumber << " amount: $" << amount << " on " << date << " new balance: $" << balance << endl;
                    
                }
                //// 2. if balance is positive and withdrawl there are sufficient funds, return 'isChargedOverDraftPenalty' as false. And make below step "withdrawl". 
                else{
                    //// ****** make withdrawl  ********//
                    double account_balance = bank.make_withdrawl(accountNumber,amount,date);
                    cout << "Withdraw from " << accountNumber << " amount: $" << amount << " on " << date << " new balance: $" << account_balance << endl;
                }
            }
        } 
        //// ************* Select '3:Check Account' ************* ////
        else if(bankTransactiontype == 3){

            int accountNumber;
            cout << "Enter Account Number ";
            cin >> accountNumber;

            //// *** retrieve account from bank **** ////
            Account* a = bank.get_account(accountNumber);
            //// retrieve customer type
            string customer_type;
              if(a->get_customer()->get_customer_type() == ADULT){
                customer_type = "Adult";
             }else if (a->get_customer()->get_customer_type()  == SENIOR){
                customer_type = "Senior";
             }else{
                customer_type = "Student";
             }
             //// retrieve account info: account number, balance, customer details
             int account_number = a->get_account_number();
             double account_balance =   a->get_balance();
             Customer* customer = a->get_customer();
             string customer_name = customer->get_name();
        
             //// ** show Customer Info **** ////
             cout << "Account: " << account_number << endl;
             cout << "Owner: " << customer_name << endl;
             cout << "Type of customer: " << customer_type << endl;
             cout << "Balance: $" << account_balance << endl;
             //// ** show Bank Transactions history  **** ////
             vector<Transaction> transaction_list =   a->get_transaction();
             for (auto transaction : transaction_list){
              cout << "      " << transaction.to_string() << endl;
             }
        }
        else if(bankTransactiontype == 4){
            isExit = true;
        }
    }


    return 0;
}
