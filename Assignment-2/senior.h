/** @file senior.h
*   @author Swe Zin Oo
*   @date 8 Feb 2024
*/

#ifndef SENIOR_H
#define SENIOR_H
#include "customer.h"


/** Senior is a class which extends the Customer class. In another words, it's a child class of Customer parent class. 
 * Senior class will inherit all member varialbes and functions of the Customer class when creating an object. The Senior class includes
 * fixed rate for saving interest, checking interest, checking charge and overdraft penaly for Senior customer.
*/
class Senior: public Customer{
    public:
     // Constants
    /** annual saving account interest rate */
    const double SAVINGS_INTEREST = 0.04;	
    /** annual checking account interest rate */	
    const double CHECKING_INTEREST = 0.01;    
    /** check charge for withdrawl in cents*/
    const double CHECK_CHARGE = 0.01;  
    /** overdraf penalty in dollar */         
    const double OVERDRAFT_PENALTY = 25.0; 
};

#endif