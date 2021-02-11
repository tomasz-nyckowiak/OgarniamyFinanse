#ifndef OPERATIONSONDATES_H
#define OPERATIONSONDATES_H

#include <iostream>
#include <time.h>
#include <windows.h>

#include "AuxiliaryMethods.h"

using namespace std;

class OperationsOnDates
{

public:

    string getCurrentDate();
    string chosenDate();
    string userChoosingTheDate();
    static string conversionNumberToDateInWantedFormat(int number);
    string conversionDateToString(int year, int month, int day);
    int getOnlyCurrentYear();
    int getOnlyCurrentMonth();
    int calculateHowManyDaysIsInAMonth(int month, bool leapYear);
    static int conversionDateToInt(string date);
    bool isGivenYearALeapYear(int year);
    bool isEnteredDateCorrect(string dateAsString, int currentYear);

    void printingRangeOfBalanceSheetForTheCurrentMonth();
    int firstDayOfTheCurrentMonth();
    int lastDayOfTheCurrentMonth();

    void printingRangeOfBalanceSheetForThePreviousMonth();
    int firstDayOfThePreviousMonth();
    int lastDayOfThePreviousMonth();

    void printingRangeOfBalanceSheetForTheChosenPeriod(string combinedStringOfTwoDates);
    string mergingDatesWhenTheyAreCorrect();
    int firstEnteredDate(string combinedStringOfTwoDates);
    int secondEnteredDate(string combinedStringOfTwoDates);
};

#endif
