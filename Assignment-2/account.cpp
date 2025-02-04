/** @file account.cpp
*   @author Swe Zin Oo
*   @date 8 Feb 2024
*   @brief The implementation file of "account.h".
*/

#include "account.h"
#include<cstdlib>

Customer* Account::get_customer() const{
    return customer;
}
double Account::get_balance() const{
    return balance;
}
int Account::get_account_number() const{
    return account_number;
}
vector<Transaction> Account::get_transaction() const{
    return transaction_array;
}
Account_type Account::get_account_type() const{
    return account_type;
 }
void Account::set_customer(Customer* c){
    customer = c;
}
void Account::set_balance(double b){
    balance = b;
}
void Account::set_Transaction(Transaction transaction){
    transaction_array.push_back(transaction);
}
void Account::createAccount(Customer* c,Account_type accType){
    // Providing a seed value
	srand((unsigned) time(NULL));
	// Get a random number for bank account number
	int random = rand() % 100;
    //assign bank account number
    account_number = random;
    customer = c;
    balance = 0;
    account_type = accType;
}