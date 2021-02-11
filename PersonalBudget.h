#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "FinancialStatement.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    FinancialStatement *financialStatement;
    const string NAME_OF_THE_FILE_WITH_INCOMES;
    const string NAME_OF_THE_FILE_WITH_EXPENSES;

public:
    PersonalBudget(string nameOfTheFileWithUsers, string nameOfTheFileWithIncomes, string nameOfTheFileWithExpenses)
        : userManager(nameOfTheFileWithUsers), NAME_OF_THE_FILE_WITH_INCOMES(nameOfTheFileWithIncomes), NAME_OF_THE_FILE_WITH_EXPENSES(nameOfTheFileWithExpenses)
    {
        financialStatement = NULL;
    }
    ~PersonalBudget()
    {
        delete financialStatement;
        financialStatement = NULL;
    };

    void userRegistering();
    void userLoggingIn();

    void addIncome();
    void addExpense();
    void balanceSheetForTheCurrentMonth();
    void balanceSheetForThePreviousMonth();
    void balanceSheetForTheChosenPeriod();
    void changePasswordOfTheLoggedUser();
    void userLoggingOut();

    bool isUserLoggedIn();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
};

#endif
