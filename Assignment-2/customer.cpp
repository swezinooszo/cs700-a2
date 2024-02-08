/** @file customer.cpp
*   @author Swe Zin Oo
*   @date 23 Jan 2024
*   @brief The implementation file of "customer.h".
*/

#include "customer.h"

string Customer::get_name() const{
    return name;
}
string Customer::get_address() const{
    return address;
}
int Customer::get_age() const{
    return age;
}
int Customer::get_telephone_number() const{
    return telephone_number;
}
int Customer::get_customer_number() const{
    return telephone_number;
}
Customer_type Customer::get_customer_type() const{
    return customer_type;
}
void Customer::set_name(string n){
    name = n;
}
void Customer::set_address(string add){
    address = add;
}
void Customer::set_age(int a){
    age = a;
}
void Customer::set_telephone_number(int t){
    telephone_number = t;
}
void Customer::set_customer_number(int c){
    customer_number = c;
}
void Customer::set_customer_type(Customer_type c){
    customer_type = c;
}