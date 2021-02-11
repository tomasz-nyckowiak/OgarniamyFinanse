#include "FileWithExpenses.h"

void FileWithExpenses::addExpenseToFile(Expense expense)
{
    CMarkup xml;

    string dateAsString = "";
    int dateAsInt = 0;
    bool fileExists = xml.Load("expenses.xml");

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    dateAsInt = expense.getDate();
    dateAsString = OperationsOnDates::conversionNumberToDateInWantedFormat(dateAsInt);

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", dateAsString);
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", expense.getAmount());
    xml.Save("expenses.xml");
}

vector <Expense> FileWithExpenses::loadExpensesFromFile(int loggedUserId)
{
    CMarkup xml;

    vector <Expense> expenses;
    Expense expense;

    int expenseId = 0, userId = 0, dateInt = 0;
    string date = "", item = "", amount = "";

    xml.Load("expenses.xml");
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Expense"))
    {
        xml.FindChildElem("UserId");
        userId = atoi(MCD_2PCSZ(xml.GetChildData()));

        if (loggedUserId == userId)
        {
            xml.ResetChildPos();

            xml.FindChildElem("ExpenseId");
            expenseId = atoi(MCD_2PCSZ(xml.GetChildData()));
            expense.setExpenseId(expenseId);

            expense.setUserId(userId);

            xml.FindChildElem("Date");
            date = xml.GetChildData();
            dateInt = OperationsOnDates::conversionDateToInt(date);
            expense.setDate(dateInt);

            xml.FindChildElem("Item");
            item = xml.GetChildData();
            expense.setItem(item);

            xml.FindChildElem("Amount");
            amount = xml.GetChildData();
            expense.setAmount(amount);

            expenses.push_back(expense);
        }
    }
    return expenses;
}

int FileWithExpenses::getIdOfTheLastExpenseFromFile()
{
    CMarkup xml;

    int lastExpenseId = 0;

    xml.Load("expenses.xml");
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Expense"))
    {
        xml.FindChildElem("ExpenseId");
        lastExpenseId = atoi(MCD_2PCSZ(xml.GetChildData()));
    }
    return lastExpenseId;
}
