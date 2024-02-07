#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "Date.h"
#include <iostream>
using namespace std;

enum Transaction_type {
    DEP, INT_CR, WD,CHKCHG,OD_PEN
};

class Transaction{

    private:
        Transaction_type transaction_type;
        double amount;
        double balance;
        Date date;

    public:
        Transaction(Transaction_type tranType, double amt, double bal, Date d)
                : transaction_type(tranType), amount(amt), balance(bal), date(d) {
                  
                }
        Transaction_type get_transaction_type();        
        double get_amount();
        double get_balance();
        Date get_date();
        string to_string()  ;
    
};
#endif