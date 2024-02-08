/** @file customer.h
*   @author Swe Zin Oo
*   @date 23 Jan 2024
*/


#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

using namespace std;
/** Customer_type is an enum class which represents different types of customer*/
enum Customer_type {
          // Data Fields
          /** SENIOR is used for senior customer */
          SENIOR,
          /** ADULT is used for adult customer */
          ADULT,
          /** ADULT is used for student customer */
          STUDENT
};
/** Customer is a class that represents the customer of a bank who makes transactions such as deposit and withdraw money */
class Customer {

    private:
        // Data Fields
        /** The name */
        string name;
         /** The address */
        string address;
         /** The age */
        int age;
         /** The telephone number */
        int telephone_number;
         /** The customer number */
        int customer_number;
         /** The customer type */
        Customer_type customer_type;
    public:
        // virtual destructor
        virtual ~Customer() {}
        // Accessor Functions
        /** Gets the customer's name.
         * @return the name as a string
        */
        string get_name() const;
         /** Gets the customer's address.
          * @return the address as a string
        */
        string get_address() const;
         /** Gets the customer's age.
          * @return the age as an int value
        */
        int get_age() const;
         /** Gets the customer's telephone number.
          * @return the telephone number as an int value
        */
        int get_telephone_number() const;
         /** Gets the customer number.
         * @return the customer number as an int value
        */
        int get_customer_number() const;
         /** Gets the customer type.
         * @return the customer type as an enum value
        */
        Customer_type get_customer_type() const;

        // Modifier Functions
        /** Sets the name field.
         * @param name The name of the customer
        */
        void set_name(string name);
        /** Sets the address field.
         * @param address The address of the customer
        */
        void set_address(string address);
        /** Sets the age field.
         * @param age The age of the customer
        */
        void set_age(int age);
         /** Sets the telephone number field.
         * @param telephone_number The telephone number of the customer
        */
        void set_telephone_number(int telephone_number);
         /** Sets the customer_number field.
         * @param customer_number The customer number
        */
        void set_customer_number(int customer_number);
         /** Sets the customer_type field.
         * @param customer_type The customer type
        */
        void set_customer_type(Customer_type customer_type);
};
#endif