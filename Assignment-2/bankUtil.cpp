/** @file bankUtil.cpp
*   @author Swe Zin Oo
*   @date 8 Feb 2024
*   @brief The implementation file of "bankUtil.h".
*/

#include <iostream>
#include <sstream>
#include <vector>
#include "bank.h"
#include "saving_account.h"
#include "checking_account.h"
#include <cmath> 


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

double calculateInterest(double amount, double rate, int numberOfDays) {
    // Convert days to years (assuming 365 days in a year)
    double years = numberOfDays / 365.0;
    // Calculate interest
    return amount * rate * years;
}

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

double roundToTwoDecimalPlaces(double number) {
    return std::round(number * 100) / 100;
}