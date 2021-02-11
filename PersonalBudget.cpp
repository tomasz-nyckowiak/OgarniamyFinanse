#include "PersonalBudget.h"

void PersonalBudget::userRegistering()
{
    userManager.userRegistering();
}

void PersonalBudget::userLoggingIn()
{
    userManager.userLoggingIn();
    if (userManager.isUserLoggedIn())
    {
        financialStatement = new FinancialStatement(NAME_OF_THE_FILE_WITH_INCOMES, NAME_OF_THE_FILE_WITH_EXPENSES, userManager.getIdOfTheLoggedUser());
    }
}

void PersonalBudget::changePasswordOfTheLoggedUser()
{
    userManager.changePasswordOfTheLoggedUser();
}

void PersonalBudget::userLoggingOut()
{
    userManager.userLoggingOut();
    delete financialStatement;
    financialStatement = NULL;
}

bool PersonalBudget::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}

void PersonalBudget::addIncome()
{
    if (userManager.isUserLoggedIn())
    {
        financialStatement -> addIncome();
    }
    else
    {
        cout << "Aby dodac przychod, nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }
}

void PersonalBudget::addExpense()
{
    if (userManager.isUserLoggedIn())
    {
        financialStatement -> addExpense();
    }
    else
    {
        cout << "Aby dodac wydatek, nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }
}

void PersonalBudget::balanceSheetForTheCurrentMonth()
{
    if (userManager.isUserLoggedIn())
    {
        financialStatement -> balanceSheetForTheCurrentMonth();
    }
}

void PersonalBudget::balanceSheetForThePreviousMonth()
{
    if (userManager.isUserLoggedIn())
    {
        financialStatement -> balanceSheetForThePreviousMonth();
    }
}

void PersonalBudget::balanceSheetForTheChosenPeriod()
{
    if (userManager.isUserLoggedIn())
    {
        financialStatement -> balanceSheetForTheChosenPeriod();
    }
}

char PersonalBudget::chooseOptionFromMainMenu()
{
    return userManager.chooseOptionFromMainMenu();
}

char PersonalBudget::chooseOptionFromUserMenu()
{
    return userManager.chooseOptionFromUserMenu();
}
