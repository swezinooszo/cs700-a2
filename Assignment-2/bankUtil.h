#pragma once
#include "bank.h"
#include <cmath> 

bool validateBankAccountNumber(int accNumber,Bank bank);
void createCheckingAccount(Customer* customer,Bank bank);
void createSavingAccount(Customer* customer,Bank bank);
bool isLeapYear(int year);
int daysInMonth(int month, int year);
int calculateDayCount(const Date& date);
double calculateInterest(double principal, double rate, int numberOfDays);
vector<string> splitString(string dateString, char toSplitValue);
Date convertStringToDate(string dateString,char toSplitValue);
double roundToTwoDecimalPlaces(double num);