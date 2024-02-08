/** @file Transaction.cpp
*   @author Swe Zin Oo
*   @date 8 Feb 2024
*   @brief The implementation file of "Transaction.h"
*/
#include "transaction.h"
#include <string>

using namespace std;

Transaction_type Transaction::get_transaction_type() const{
     return transaction_type;
}
double Transaction::get_amount() const{
     return amount;
}
double Transaction::get_balance() const{
    return balance;
}
Date Transaction::get_date() const{
     return date;
}
string Transaction::to_string()  {
        string transType;
        if(transaction_type == DEP){
            transType = "DEP";
        }else if(transaction_type == INT_CR){
             transType = "INT CR";
        }else if(transaction_type == WD){
             transType = "WD";
        }else if(transaction_type == CHKCHG){
             transType = "CHKCHG";
        }else if(transaction_type == OD_PEN){
             transType = "OD_PEN";
        }
       return  transType + "  " + date.to_string() + "  $  " + std::to_string(amount) +  "  $  " + std::to_string(balance);
}