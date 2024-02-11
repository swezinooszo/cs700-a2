/** @file transaction.cpp
*   @author Swe Zin Oo
*   @date 8 Feb 2024
*   @brief The implementation file of "transaction.h"
*/
#include "transaction.h"
#include <string>
#include <iomanip>
#include <sstream>

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

string Transaction::to_string() const {
        ostringstream result;
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
             transType = "OD PEN";
        }
     
          // Convert 'amount' double value to string with two decimal places
          std::string stramount = std::to_string(amount);
          size_t decimalPos = stramount.find('.');
          if (decimalPos != std::string::npos && decimalPos + 3 < stramount.size()) {
               stramount.resize(decimalPos + 3);
          }

          // Convert 'balance' double value to string with two decimal places
          std::string strbalance = std::to_string(balance);
          size_t decimalPos1 = strbalance.find('.');
          if (decimalPos1 != std::string::npos && decimalPos1 + 3 < strbalance.size()) {
               strbalance.resize(decimalPos1 + 3);
          }

          result
          << setw(6) << right << transType << " " 
          << setw(10) << right << date.to_string() << " " 
          << "$ " 
          << setw(6) << right << stramount << " " 
          << "$ " 
          << setw(6) << right << strbalance ;

     return result.str();
}
