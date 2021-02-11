#include "OperationsOnDates.h"

string OperationsOnDates::getCurrentDate()
{
    string dateAsString = "";
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,80,"%Y-%m-%d",timeinfo);
    dateAsString = buffer;
    return dateAsString;
}

int OperationsOnDates::getOnlyCurrentYear()
{
    string dateAsString = "", onlyYear = "";
    int year = 0;

    dateAsString = getCurrentDate();
    onlyYear = dateAsString.substr(0,4);
    year = AuxiliaryMethods::conversionStringToInt(onlyYear);
    return year;
}

int OperationsOnDates::getOnlyCurrentMonth()
{
    string dateAsString = "", onlyMonth = "";
    int month = 0;

    dateAsString = getCurrentDate();
    onlyMonth = dateAsString.substr(5,2);
    month = AuxiliaryMethods::conversionStringToInt(onlyMonth);
    return month;
}

int OperationsOnDates::calculateHowManyDaysIsInAMonth(int month, bool leapYear)
{
    int daysInAMonth = 0;

    if (month == 2)
    {
        if (leapYear)
        {
            daysInAMonth = 29;
        }
        else
        {
            daysInAMonth = 28;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        daysInAMonth = 30;
    }
    else
    {
        daysInAMonth = 31;
    }
    return daysInAMonth;
}

bool OperationsOnDates::isGivenYearALeapYear(int year)
{
    bool leapYear = false;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        leapYear = true;
    }
    return leapYear;
}

bool OperationsOnDates::isEnteredDateCorrect(string dateAsString, int currentYear)
{
    string yearAsString = "", monthAsString = "", dayAsString = "";
    int year = 0, month = 0, day = 0, numberOfDaysInAMonth = 0;
    char signDash = '-';
    bool isYearALeapYear = false;
    bool isDateCorrect = true;

    if (dateAsString.length() != 10)
    {
        isDateCorrect = false;
        return isDateCorrect;
    }
    else
    {
        if (dateAsString[4] != signDash || dateAsString[7] != signDash)
        {
            isDateCorrect = false;
            return isDateCorrect;
        }
        else
        {
            yearAsString = dateAsString.substr(0,4);

            if (AuxiliaryMethods::isSignANumber(yearAsString) == false)
            {
                isDateCorrect = false;
                return isDateCorrect;
            }

            year = AuxiliaryMethods::conversionStringToInt(yearAsString);
            monthAsString = dateAsString.substr(5,2);

            if (AuxiliaryMethods::isSignANumber(monthAsString) == false)
            {
                isDateCorrect = false;
                return isDateCorrect;
            }

            month = AuxiliaryMethods::conversionStringToInt(monthAsString);
            dayAsString = dateAsString.substr(8,2);

            if (AuxiliaryMethods::isSignANumber(dayAsString) == false)
            {
                isDateCorrect = false;
                return isDateCorrect;
            }

            day = AuxiliaryMethods::conversionStringToInt(dayAsString);

            if (year < 2000 || year > currentYear)
            {
                isDateCorrect = false;
                return isDateCorrect;
            }
            else
            {
                if (month < 1 || month > 12)
                {
                    isDateCorrect = false;
                    return isDateCorrect;
                }
                else
                {
                    if (day < 1 || day > 31)
                    {
                        isDateCorrect = false;
                        return isDateCorrect;
                    }
                    else
                    {
                        if (!isGivenYearALeapYear(year))
                        {
                            ;
                        }
                        else
                        {
                            isYearALeapYear = true;
                        }

                        numberOfDaysInAMonth = calculateHowManyDaysIsInAMonth(month, isYearALeapYear);

                        if (day <= numberOfDaysInAMonth)
                        {
                            return isDateCorrect;
                        }
                        else
                        {
                            isDateCorrect = false;
                            return isDateCorrect;
                        }
                    }
                }
            }
        }
    }
}

string OperationsOnDates::chosenDate()
{
    string enteredDate = "";
    int currentYear = 0;

    currentYear = getOnlyCurrentYear();

    while (true)
    {
        cout << "Podaj date (data musi byc w formacie <rrrr-mm-dd>): ";
        enteredDate = AuxiliaryMethods::loadLine();

        if (isEnteredDateCorrect(enteredDate, currentYear) == false)
        {
            cout << "Wprowadzono bledna date! Sprobuj ponownie." << endl;
        }
        else
        {
            return enteredDate;
        }
    }
}

string OperationsOnDates::userChoosingTheDate()
{
    string date = "";
    char choice;

    while (true)
    {
        cout << "Czy dotyczy on dnia dzisiejszego (T/N)? ";
        choice = AuxiliaryMethods::loadSign();

        if (choice == 'T' || choice == 't')
        {
            date = getCurrentDate();
            break;
        }
        else if (choice == 'N' || choice == 'n')
        {
            date = chosenDate();
            break;
        }
        else
        {
            cout << "Wprowadzono bledny znak! Sprobuj ponownie." << endl;
        }
    }
    return date;
}

int OperationsOnDates::conversionDateToInt(string date)
{
    string year = "", month = "", day = "", sumOfStrings = "";
    int result = 0;

    year = date.substr(0,4);
    month = date.substr(5,2);
    day = date.substr(8,2);
    sumOfStrings = year + month + day;
    result = AuxiliaryMethods::conversionStringToInt(sumOfStrings);
    return result;
}

string OperationsOnDates::conversionNumberToDateInWantedFormat(int number)
{
    string dateInWantedFormat = "";

    dateInWantedFormat = AuxiliaryMethods::conversionIntToString(number);
    dateInWantedFormat.insert(4, "-");
    dateInWantedFormat.insert(7, "-");
    return dateInWantedFormat;
}

string OperationsOnDates::conversionDateToString(int year, int month, int day)
{
    string dateAsString = "", yearAsString = "", monthAsString = "", dayAsString = "";

    yearAsString = AuxiliaryMethods::conversionIntToString(year);
    monthAsString = AuxiliaryMethods::conversionIntToString(month);

    if (month < 10)
    {
        monthAsString = "0" + monthAsString;
    }

    dayAsString = AuxiliaryMethods::conversionIntToString(day);

    if (day < 10)
    {
        dayAsString = "0" + dayAsString;
    }

    dateAsString = yearAsString + "-" + monthAsString + "-" + dayAsString;
    return dateAsString;
}

void OperationsOnDates::printingRangeOfBalanceSheetForTheCurrentMonth()
{
    string currentDateAsString = "", firstDayOfTheDate = "", lastDayOfTheDate = "";
    int year = 0, month = 0, numberOfDaysInAMonth = 0;
    bool yearIsALeapYear = false;

    currentDateAsString = getCurrentDate();
    firstDayOfTheDate = currentDateAsString;
    firstDayOfTheDate.replace(8,2, "01");

    month = getOnlyCurrentMonth();
    year = getOnlyCurrentYear();
    yearIsALeapYear = isGivenYearALeapYear(year);
    numberOfDaysInAMonth = calculateHowManyDaysIsInAMonth(month, yearIsALeapYear);
    lastDayOfTheDate = conversionDateToString(year, month, numberOfDaysInAMonth);

    cout << "         (Od " <<  firstDayOfTheDate << " do " << lastDayOfTheDate << ")" << endl;
}

int OperationsOnDates::firstDayOfTheCurrentMonth()
{
    string dateAsString = "", firstDayOfTheDate = "";
    int firstDayAsInt = 0;

    dateAsString = getCurrentDate();
    firstDayOfTheDate = dateAsString;
    firstDayOfTheDate.replace(8,2, "01");
    firstDayAsInt = conversionDateToInt(firstDayOfTheDate);
    return firstDayAsInt;
}

int OperationsOnDates::lastDayOfTheCurrentMonth()
{
    string currentDateAsString = "", lastDayOfTheDate = "";
    int year = 0, month = 0, numberOfDaysInAMonth = 0, ourSumOfStringsAsInt = 0;
    bool yearIsALeapYear = false;

    currentDateAsString = getCurrentDate();
    year = getOnlyCurrentYear();
    month = getOnlyCurrentMonth();
    yearIsALeapYear = isGivenYearALeapYear(year);
    numberOfDaysInAMonth = calculateHowManyDaysIsInAMonth(month, yearIsALeapYear);
    lastDayOfTheDate = conversionDateToString(year, month, numberOfDaysInAMonth);
    ourSumOfStringsAsInt = conversionDateToInt(lastDayOfTheDate);
    return ourSumOfStringsAsInt;
}

void OperationsOnDates::printingRangeOfBalanceSheetForThePreviousMonth()
{
    string currentDateAsString = "", yearAsString = "", monthAsString = "";
    string firstDayOfThePreviousMonth = "", lastDayOfThePreviousMonth = "";
    int currentYear = 0, currentMonth = 0, previousMonth = 0, numberOfDaysInAMonth = 0;
    bool yearIsALeapYear = false;

    currentDateAsString = getCurrentDate();
    yearAsString = currentDateAsString.substr(0,4);
    currentYear = AuxiliaryMethods::conversionStringToInt(yearAsString);
    monthAsString = currentDateAsString.substr(5,2);
    currentMonth = AuxiliaryMethods::conversionStringToInt(monthAsString);

    previousMonth = currentMonth - 1;

    if (previousMonth == 0)
    {
        previousMonth = 12;

        currentYear = currentYear - 1;
    }

    yearIsALeapYear = isGivenYearALeapYear(currentYear);
    numberOfDaysInAMonth = calculateHowManyDaysIsInAMonth(previousMonth, yearIsALeapYear);
    firstDayOfThePreviousMonth = conversionDateToString(currentYear, previousMonth, 1);
    lastDayOfThePreviousMonth = conversionDateToString(currentYear, previousMonth, numberOfDaysInAMonth);

    cout << "         (Od " << firstDayOfThePreviousMonth << " do " << lastDayOfThePreviousMonth << ")" << endl;
}

int OperationsOnDates::firstDayOfThePreviousMonth()
{
    string currentDateAsString = "", yearAsString = "", monthAsString = "";
    string firstDayOfThePreviousMonth = "";
    int currentYear = 0, currentMonth = 0, previousMonth = 0, result = 0;

    currentDateAsString = getCurrentDate();
    yearAsString = currentDateAsString.substr(0,4);
    currentYear = AuxiliaryMethods::conversionStringToInt(yearAsString);
    monthAsString = currentDateAsString.substr(5,2);
    currentMonth = AuxiliaryMethods::conversionStringToInt(monthAsString);

    previousMonth = currentMonth - 1;

    if (previousMonth == 0)
    {
        previousMonth = 12;

        currentYear = currentYear - 1;
    }

    firstDayOfThePreviousMonth = conversionDateToString(currentYear, previousMonth, 1);
    result = conversionDateToInt(firstDayOfThePreviousMonth);
    return result;
}

int OperationsOnDates::lastDayOfThePreviousMonth()
{
    string currentDateAsString = "", yearAsString = "", monthAsString = "";
    string lastDayOfThePreviousMonth = "";
    int currentYear = 0, currentMonth = 0, previousMonth = 0, numberOfDaysInAMonth = 0, result = 0;
    bool yearIsALeapYear = false;

    currentDateAsString = getCurrentDate();
    yearAsString = currentDateAsString.substr(0,4);
    currentYear = AuxiliaryMethods::conversionStringToInt(yearAsString);
    monthAsString = currentDateAsString.substr(5,2);
    currentMonth = AuxiliaryMethods::conversionStringToInt(monthAsString);

    previousMonth = currentMonth - 1;

    if (previousMonth == 0)
    {
        previousMonth = 12;

        currentYear = currentYear - 1;
    }

    yearIsALeapYear = isGivenYearALeapYear(currentYear);
    numberOfDaysInAMonth = calculateHowManyDaysIsInAMonth(previousMonth, yearIsALeapYear);
    lastDayOfThePreviousMonth = conversionDateToString(currentYear, previousMonth, numberOfDaysInAMonth);
    result = conversionDateToInt(lastDayOfThePreviousMonth);
    return result;
}

string OperationsOnDates::mergingDatesWhenTheyAreCorrect()
{
    string enteredFirstDate = "", enteredSecondDate = "", mergingDates = "";
    int currentYear = 0, firstDateAsInt = 0, secondDateAsInt = 0;

    currentYear = getOnlyCurrentYear();

    cout << "Podaj zakres (data musi byc w formacie <rrrr-mm-dd>):" << endl;

    while (true)
    {
        cout << "Od: ";
        enteredFirstDate = AuxiliaryMethods::loadLine();

        if (isEnteredDateCorrect(enteredFirstDate, currentYear) == false)
        {
            cout << "Wprowadzono bledna date! Sprobuj ponownie." << endl;
        }
        else
        {
            while (true)
            {
                cout << "Do: ";
                enteredSecondDate = AuxiliaryMethods::loadLine();

                if (isEnteredDateCorrect(enteredSecondDate, currentYear) == false)
                {
                    cout << "Wprowadzono bledna date! Sprobuj ponownie." << endl;
                }
                else
                {
                    break;
                }
            }

            firstDateAsInt = conversionDateToInt(enteredFirstDate);
            secondDateAsInt = conversionDateToInt(enteredSecondDate);

            if (secondDateAsInt < firstDateAsInt)
            {
                cout << "Wprowadzono bledny zakres! Sprobuj ponownie." << endl;
            }
            else
            {
                break;
            }
        }
    }

    mergingDates = enteredFirstDate + enteredSecondDate;
    return mergingDates;
}

void OperationsOnDates::printingRangeOfBalanceSheetForTheChosenPeriod(string combinedStringOfTwoDates)
{
    string firstDate = "", secondDate = "";

    firstDate = combinedStringOfTwoDates.substr(0, 10);
    secondDate = combinedStringOfTwoDates.substr(10, 20);

    cout << "         (Od " << firstDate << " do " << secondDate << ")" << endl;
}

int OperationsOnDates::firstEnteredDate(string combinedStringOfTwoDates)
{
    string firstDate = "";
    int dateAsInt = 0;

    firstDate = combinedStringOfTwoDates.substr(0, 10);
    dateAsInt = conversionDateToInt(firstDate);
    return dateAsInt;
}

int OperationsOnDates::secondEnteredDate(string combinedStringOfTwoDates)
{
    string secondDate = "";
    int dateAsInt = 0;

    secondDate = combinedStringOfTwoDates.substr(10, 20);
    dateAsInt = conversionDateToInt(secondDate);
    return dateAsInt;
}
