/** @file student.cpp
*   @author Swe Zin Oo
*   @date 8 Feb 2024
*   @brief The implementation file of "student.h".
*/

#include "student.h"

double Student::get_saving_interest() const{
    return SAVINGS_INTEREST;
}
double Student::get_checking_interest() const{
    return CHECKING_INTEREST;
}
double Student::get_check_charge() const{
    return CHECK_CHARGE;
}
double Student::get_overdraft_penalty_charge() const{
    return OVERDRAFT_PENALTY;
}