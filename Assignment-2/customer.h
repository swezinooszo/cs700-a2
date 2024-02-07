#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

using namespace std;
enum Customer_type {
                SENIOR,ADULT,STUDENT
};
class Customer {

    private:
        string name;
        string address;
        int age;
        int telephone_number;
        int customer_number;
        Customer_type customer_type;
    public:
        virtual ~Customer() {}
        string get_name() const;
        string get_address() const;
        int get_age() const;
        int get_telephone_number() const;
        int get_customer_number() const;
        Customer_type get_customer_type() const;

        void set_name(string name);
        void set_address(string address);
        void set_age(int age);
        void set_telephone_number(int telephone_number);
        void set_customer_number(int customer_number);
        void set_customer_type(Customer_type ctype);
};
#endif