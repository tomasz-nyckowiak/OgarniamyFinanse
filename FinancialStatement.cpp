#include "FinancialStatement.h"

void FinancialStatement::addIncome()
{
    Income income;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;

    income = giveInformationAboutNewIncome();

    incomes.push_back(income);

    fileWithIncomes.addIncomeToFile(income);

    cout << "Nowy przychod zostal dodany." << endl;
    system("pause");
}

Income FinancialStatement::giveInformationAboutNewIncome()
{
    Income income;

    string enteredDate = "", item = "", amount = "";
    int actuallDateInVector = 0;

    income.setIncomeId(fileWithIncomes.getIdOfTheLastIncomeFromFile() + 1);
    income.setUserId(LOGGED_USER_ID);

    enteredDate = operationsOnDates.userChoosingTheDate();
    actuallDateInVector = operationsOnDates.conversionDateToInt(enteredDate);

    cout << "Podaj czego dotyczy: ";
    item = AuxiliaryMethods::loadLine();

    amount = money.enteringAmount();

    income.setDate(actuallDateInVector);
    income.setItem(item);
    income.setAmount(amount);
    return income;
}

void FinancialStatement::addExpense()
{
    Expense expense;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    expense = giveInformationAboutNewExpense();

    expenses.push_back(expense);

    fileWithExpenses.addExpenseToFile(expense);

    cout << "Nowy wydatek zostal dodany." << endl;
    system("pause");
}

Expense FinancialStatement::giveInformationAboutNewExpense()
{
    Expense expense;

    string enteredDate = "", item = "", amount = "";
    int actuallDateInVector = 0;

    expense.setExpenseId(fileWithExpenses.getIdOfTheLastExpenseFromFile() + 1);
    expense.setUserId(LOGGED_USER_ID);

    enteredDate = operationsOnDates.userChoosingTheDate();
    actuallDateInVector = operationsOnDates.conversionDateToInt(enteredDate);

    cout << "Podaj czego dotyczy: ";
    item = AuxiliaryMethods::loadLine();

    amount = money.enteringAmount();

    expense.setDate(actuallDateInVector);
    expense.setItem(item);
    expense.setAmount(amount);
    return expense;
}

void FinancialStatement::balanceSheetForTheCurrentMonth()
{
    system("cls");
    vector <Income> selectedIncomesForTheCurrentMonth;
    vector <Expense> selectedExpensesForTheCurrentMonth;
    int firstDay = 0, lastDay = 0;

    cout << "      >>> BILANS Z BIEZACEGO MIESIACA <<<" << endl;
    operationsOnDates.printingRangeOfBalanceSheetForTheCurrentMonth();
    cout << "-----------------------------------------------" << endl;
    cout << endl;

    firstDay = operationsOnDates.firstDayOfTheCurrentMonth();
    lastDay = operationsOnDates.lastDayOfTheCurrentMonth();

    cout << "               >>> PRZYCHODY <<<" << endl;
    cout << "-----------------------------------------------" << endl;

    for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if (itr -> getDate() <= lastDay && itr -> getDate() >= firstDay)
        {
            selectedIncomesForTheCurrentMonth.push_back(*itr);
        }
    }

    if (!selectedIncomesForTheCurrentMonth.empty())
    {
        cout << endl;
        printingSelectedIncomes(selectedIncomesForTheCurrentMonth);
    }
    else
    {
        cout << endl << "Brak przychodow." << endl << endl;
    }

    cout << "                >>> WYDATKI <<<" << endl;
    cout << "-----------------------------------------------" << endl;

    for (vector <Expense> :: iterator itr2 = expenses.begin(); itr2 != expenses.end(); itr2++)
    {
        if (itr2 -> getDate() <= lastDay && itr2 -> getDate() >= firstDay)
        {
            selectedExpensesForTheCurrentMonth.push_back(*itr2);
        }
    }

    if (!selectedExpensesForTheCurrentMonth.empty())
    {
        cout << endl;
        printingSelectedExpenses(selectedExpensesForTheCurrentMonth);
    }
    else
    {
        cout << endl << "Brak wydatkow." << endl << endl;
    }

    cout << "             >>> BILANS KONCOWY <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    printingFinalBalance(selectedIncomesForTheCurrentMonth, selectedExpensesForTheCurrentMonth);

    cout << endl;
    system("pause");
}

void FinancialStatement::balanceSheetForThePreviousMonth()
{
    system("cls");
    vector <Income> selectedIncomesForThePreviousMonth;
    vector <Expense> selectedExpensesForThePreviousMonth;
    int firstDay = 0, lastDay = 0;

    cout << "      >>> BILANS Z POPRZEDNIEGO MIESIACA <<<" << endl;
    operationsOnDates.printingRangeOfBalanceSheetForThePreviousMonth();
    cout << "-----------------------------------------------" << endl;
    cout << endl;

    firstDay = operationsOnDates.firstDayOfThePreviousMonth();
    lastDay = operationsOnDates.lastDayOfThePreviousMonth();

    cout << "               >>> PRZYCHODY <<<" << endl;
    cout << "-----------------------------------------------" << endl;

    for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if (itr -> getDate() <= lastDay && itr -> getDate() >= firstDay)
        {
            selectedIncomesForThePreviousMonth.push_back(*itr);
        }
    }

    if (!selectedIncomesForThePreviousMonth.empty())
    {
        cout << endl;
        printingSelectedIncomes(selectedIncomesForThePreviousMonth);
    }
    else
    {
        cout << endl << "Brak przychodow." << endl << endl;
    }

    cout << "                >>> WYDATKI <<<" << endl;
    cout << "-----------------------------------------------" << endl;

    for (vector <Expense> :: iterator itr2 = expenses.begin(); itr2 != expenses.end(); itr2++)
    {
        if (itr2 -> getDate() <= lastDay && itr2 -> getDate() >= firstDay)
        {
            selectedExpensesForThePreviousMonth.push_back(*itr2);
        }
    }

    if (!selectedExpensesForThePreviousMonth.empty())
    {
        cout << endl;
        printingSelectedExpenses(selectedExpensesForThePreviousMonth);
    }
    else
    {
        cout << endl << "Brak wydatkow." << endl << endl;
    }

    cout << "             >>> BILANS KONCOWY <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    printingFinalBalance(selectedIncomesForThePreviousMonth, selectedExpensesForThePreviousMonth);

    cout << endl;
    system("pause");
}

void FinancialStatement::balanceSheetForTheChosenPeriod()
{
    system("cls");
    vector <Income> selectedIncomesForTheChosenPeriod;
    vector <Expense> selectedExpensesForTheChosenPeriod;
    string combinedDatesAsStrings = "";
    int firstDate = 0, lastDate = 0;

    combinedDatesAsStrings = operationsOnDates.mergingDatesWhenTheyAreCorrect();

    system("cls");
    cout << "      >>> BILANS Z WYBRANEGO OKRESU <<<" << endl;
    operationsOnDates.printingRangeOfBalanceSheetForTheChosenPeriod(combinedDatesAsStrings);
    cout << "-----------------------------------------------" << endl;
    cout << endl;

    firstDate = operationsOnDates.firstEnteredDate(combinedDatesAsStrings);
    lastDate = operationsOnDates.secondEnteredDate(combinedDatesAsStrings);

    cout << "               >>> PRZYCHODY <<<" << endl;
    cout << "-----------------------------------------------" << endl;

    for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if (itr -> getDate() <= lastDate && itr -> getDate() >= firstDate)
        {
            selectedIncomesForTheChosenPeriod.push_back(*itr);
        }
    }

    if (!selectedIncomesForTheChosenPeriod.empty())
    {
        cout << endl;
        printingSelectedIncomes(selectedIncomesForTheChosenPeriod);
    }
    else
    {
        cout << endl << "Brak przychodow." << endl << endl;
    }

    cout << "                >>> WYDATKI <<<" << endl;
    cout << "-----------------------------------------------" << endl;

    for (vector <Expense> :: iterator itr2 = expenses.begin(); itr2 != expenses.end(); itr2++)
    {
        if (itr2 -> getDate() <= lastDate && itr2 -> getDate() >= firstDate)
        {
            selectedExpensesForTheChosenPeriod.push_back(*itr2);
        }
    }

    if (!selectedExpensesForTheChosenPeriod.empty())
    {
        cout << endl;
        printingSelectedExpenses(selectedExpensesForTheChosenPeriod);
    }
    else
    {
        cout << endl << "Brak wydatkow." << endl << endl;
    }

    cout << "             >>> BILANS KONCOWY <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    printingFinalBalance(selectedIncomesForTheChosenPeriod, selectedExpensesForTheChosenPeriod);

    cout << endl;
    system("pause");
}

void FinancialStatement::printingSelectedIncomes(vector <Income> selectedIncomes)
{
    sort(selectedIncomes.begin(), selectedIncomes.end());

    for (vector <Income> :: iterator itr = selectedIncomes.begin(); itr != selectedIncomes.end(); itr++)
    {
        showInformationAboutIncome(*itr);
    }
    cout << endl;
}

void FinancialStatement::printingSelectedExpenses(vector <Expense> selectedExpenses)
{
    sort(selectedExpenses.begin(), selectedExpenses.end());

    for (vector <Expense> :: iterator itr = selectedExpenses.begin(); itr != selectedExpenses.end(); itr++)
    {
        showInformationAboutExpense(*itr);
    }
    cout << endl;
}

void FinancialStatement::printingFinalBalance(vector <Income> selectedIncomes, vector <Expense> selectedExpenses)
{
    float sumOfIncomes = 0, sumOfExpenses = 0;

    for (vector <Income> :: iterator itr = selectedIncomes.begin(); itr != selectedIncomes.end(); itr++)
    {
        sumOfIncomes += (money.convertingAmountFromStringToFloat(itr -> getAmount()));
    }
    cout << endl;
    cout << "Suma przychodow: " << sumOfIncomes << endl;

    for (vector <Expense> :: iterator itr2 = selectedExpenses.begin(); itr2 != selectedExpenses.end(); itr2++)
    {
        sumOfExpenses += (money.convertingAmountFromStringToFloat(itr2 -> getAmount()));
    }
    cout << "Suma wydatkow: " << sumOfExpenses << endl;
    cout << "Roznica: " << sumOfIncomes - sumOfExpenses << endl;
}

void FinancialStatement::showInformationAboutIncome(Income income)
{
    cout << endl << "Id Przychodu:                   " << income.getIncomeId() << endl;
    cout << "Id Uzytkownika:                 " << income.getUserId() << endl;
    cout << "Data:                           " << operationsOnDates.conversionNumberToDateInWantedFormat(income.getDate()) << endl;
    cout << "Czego dotyczy:                  " << income.getItem() << endl;
    cout << "Kwota:                          " << income.getAmount() << endl;
}

void FinancialStatement::showInformationAboutExpense(Expense expense)
{
    cout << endl << "Id Wydatku:                     " << expense.getExpenseId() << endl;
    cout << "Id Uzytkownika:                 " << expense.getUserId() << endl;
    cout << "Data:                           " << operationsOnDates.conversionNumberToDateInWantedFormat(expense.getDate()) << endl;
    cout << "Czego dotyczy:                  " << expense.getItem() << endl;
    cout << "Kwota:                          " << expense.getAmount() << endl;
}
