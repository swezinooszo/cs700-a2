/** @file senior.cpp
*   @author Swe Zin Oo
*   @date 8 Feb 2024
*   @brief The implementation file of "senior.h".
*/

#include "senior.h"

double Senior::get_saving_interest() const{
    return SAVINGS_INTEREST;
}
double Senior::get_checking_interest() const{
    return CHECKING_INTEREST;
}
double Senior::get_check_charge() const{
    return CHECK_CHARGE;
}
double Senior::get_overdraft_penalty_charge() const{
    return OVERDRAFT_PENALTY;
}