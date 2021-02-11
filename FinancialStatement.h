#ifndef FINANCIALSTATEMENT_H
#define FINANCIALSTATEMENT_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "Income.h"
#include "Expense.h"
#include "OperationsOnDates.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "Money.h"
#include "Finances.h"

using namespace std;

class FinancialStatement
{
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;
    OperationsOnDates operationsOnDates;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;
    Money money;

    Income giveInformationAboutNewIncome();
    void showInformationAboutIncome(Income income);
    Expense giveInformationAboutNewExpense();
    void showInformationAboutExpense(Expense expense);

public:
    FinancialStatement(string nameOfTheFileWithIncomes, string nameOfTheFileWithExpenses, int loggedUserId)
        : fileWithIncomes(nameOfTheFileWithIncomes), fileWithExpenses(nameOfTheFileWithExpenses), LOGGED_USER_ID(loggedUserId)
    {
        incomes = fileWithIncomes.loadIncomesFromFile(LOGGED_USER_ID);
        expenses = fileWithExpenses.loadExpensesFromFile(LOGGED_USER_ID);
    };

    void addIncome();
    void addExpense();
    void balanceSheetForTheCurrentMonth();
    void balanceSheetForThePreviousMonth();
    void balanceSheetForTheChosenPeriod();

    void printingSelectedIncomes(vector <Income> selectedIncomes);
    void printingSelectedExpenses(vector <Expense> selectedExpenses);
    void printingFinalBalance(vector <Income> selectedIncomes, vector <Expense> selectedExpenses);
};

#endif
