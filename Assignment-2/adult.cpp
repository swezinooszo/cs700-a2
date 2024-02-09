/** @file adult.cpp
*   @author Swe Zin Oo
*   @date 8 Feb 2024
*   @brief The implementation file of "adult.h".
*/

#include "adult.h"

double Adult::get_saving_interest() const{
    return SAVINGS_INTEREST;
}
double Adult::get_checking_interest() const{
    return CHECKING_INTEREST;
}
double Adult::get_check_charge() const{
    return CHECK_CHARGE;
}
double Adult::get_overdraft_penalty_charge() const{
    return OVERDRAFT_PENALTY;
}