#ifndef  ADULT_H
#define  ADULT_H
#include "customer.h"

class Adult: public Customer {
        public:
        const double SAVINGS_INTEREST = 0.03;		// annual rate
        const double CHECKING_INTEREST = 0.01;       // annual rate. Yes! this is interest rate for the checking account.
        const double CHECK_CHARGE = 0.03;            //cents for withdrawal
        const double OVERDRAFT_PENALTY = 25.0;       //dollar
};
#endif