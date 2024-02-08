/** @file student.h
*   @author Swe Zin Oo
*   @date 8 Feb 2024
*/

#ifndef STUDENT_H
#define STUDENT_H
#include "customer.h"

/** Student is a class which extends the Customer class. In another words, it's a child class of Customer parent class. 
 * Student class will inherit all member varialbes and functions of the Customer class when creating an object. The Student class includes
 * fixed rate for saving interest, checking interest, checking charge and overdraft penaly for Student customer.
*/

class Student: public Customer{
    public:
     // Constants
    /** annual saving account interest rate */
    const double SAVINGS_INTEREST = 0.04;
    /** annual checking account interest rate */	
    const double CHECKING_INTEREST = 0.01;		
    /** check charge for withdrawl in cents*/
    const double CHECK_CHARGE = 0.02; 	
    /** overdraf penalty in dollar */  		
    const double OVERDRAFT_PENALTY = 25.0;
};

#endif