#include <iostream>
#include <sstream>
#include <vector>
#include "bank.h"
#include "saving_account.h"
#include "checking_account.h"
#include <cmath> 

bool validateBankAccountNumber(int accNumber,Bank bank){
    std::vector<Account*> accounts = bank.get_accounts();
    bool isAccountValid;
    for (size_t i = 0; i < accounts.size(); ++i) {
    
        if(accounts[i]->get_account_number() == accNumber){
            isAccountValid = true;
            break;
        }
    }
    return isAccountValid;
}

// create checking account based on entered customer details, account type and bank object to add created account.
void createCheckingAccount(Customer* customer,Bank bank){
    Checking_Account* checking_account = new Checking_Account();
    Account_type accType = CHECKING;
    checking_account->createAccount(customer,accType);
    bank.add_account(checking_account);
    cout << "Account: " << checking_account->get_account_number() << " Added" ;
    cout << endl;
}

void createSavingAccount(Customer* customer,Bank bank){
    Saving_Account* saving_account = new Saving_Account();
    Account_type accType = SAVING;
    saving_account->createAccount(customer,accType);
    bank.add_account(saving_account);
    cout << "Account: " << saving_account->get_account_number() << " Added" ;
    cout << endl;
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 2: // February
            return isLeapYear(year) ? 29 : 28;
        case 4: case 6: case 9: case 11: // April, June, September, November
            return 30;
        default: // January, March, May, July, August, October, December
            return 31;
    }
}

int calculateDayCount(const Date& date) {
    // Reference date (January 1, 1900)
    const Date referenceDate(1900, 1, 1);
    
    // Number of days between the reference date and the given date
    int days = 0;

    // Calculate the number of days in each year between the reference year and the given year
    for (int year = referenceDate.Year(); year < date.Year(); ++year) {
        days += isLeapYear(year) ? 366 : 365;
    }

    // Calculate the number of days in each month between January and the given month
    for (int month = 1; month < date.Month(); ++month) {
        days += daysInMonth(month, date.Year());
    }

    // Add the number of days in the given month
    days += date.Day();

    return days;
}

// Function to calculate simple interest based on number of days
double calculateInterest(double amount, double rate, int numberOfDays) {
    // Convert days to years (assuming 365 days in a year)
    double years = numberOfDays / 365.0;
    // cout << "before round years "<< years << endl; 
    // double rounded_years = std::round(years * 100) / 100;
    cout << "after round years "<< years << endl; 
    // Calculate interest
    return amount * rate * years;
}

// Function to split a string into substrings based on a delimiter
vector<string> splitString(string dateString, char toSplitValue) {
    vector<string> resultStringArray;
    istringstream iss(dateString);
    string resultString;
    while (getline(iss, resultString, toSplitValue)) {
        resultStringArray.push_back(resultString);
    }
    return resultStringArray;
}

Date convertStringToDate(string dateString,char toSplitValue){
       /// *** convert dateString to dateFormat ****
        vector<string> stringArray = splitString(dateString,toSplitValue);
        int day = stoi(stringArray[2]);
        int month = stoi(stringArray[1]);
        int year = stoi(stringArray[0]);
        Date date(day,month,year);
        return date;
}

double roundToTwoDecimalPlaces(double num) {
    return std::round(num * 100) / 100;
}