/** @file bankUtil.h
*   @author Swe Zin Oo
*   @date 8 Feb 2024
*   @brief This is the utility class of this banking program. This includes all the necesary functions which is used in bank transactions such as
*   making deposit, making withdrawal, calculating interest and charge overdraft penalty
*/

#pragma once
#include "bank.h"
#include <cmath> 

/** check whether the year is leap year or not
* @param year the year
* @return return boolean value true if the year is leap year. unless return false
*/
bool isLeapYear(int year);
/** Find the number of days of the month
* @param month the month
* @param year the year
* @return number of days as an integer value
*/
int daysInMonth(int month, int year);
/** Calculate the number of days of the provided Date
* @param date the Date object
* @return number of days as an integer value
*/
int calculateDayCount(const Date& date);
/** Calculate interest based on the amount, interest rate and number of days
* @param amount the amount
* @param rate the interest rate
* @param numberOfDays the number of days that the balance hold
* @return calculate interested amount as a double value
*/
double calculateInterest(double amount, double rate, int numberOfDays);
/** Split the string based on provided special character and convert to an array
* @param dateString The Date object value with string format
* @param toSplitValue the special character which will be used to split the dateString
* @return an vector string array of date value which is already removed special character
*/
vector<string> splitString(string dateString, char toSplitValue);
/** Convert Date value with string format to Date object
* @param dateString The Date object value with string format
* @param toSplitValue the special character which will be used to split the dateString
* @return formatted date object 
*/
Date convertStringToDate(string dateString,char toSplitValue);
/** round provided double value to two decimal places 
* @param number the number value
* @return formatted number value 
*/
double roundToTwoDecimalPlaces(double number);