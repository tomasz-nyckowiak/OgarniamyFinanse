#include "FileWithIncomes.h"

void FileWithIncomes::addIncomeToFile(Income income)
{
    CMarkup xml;

    string dateAsString = "";
    int dateAsInt = 0;
    bool fileExists = xml.Load("incomes.xml");

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    dateAsInt = income.getDate();
    dateAsString = OperationsOnDates::conversionNumberToDateInWantedFormat(dateAsInt);

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", dateAsString);
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", income.getAmount());
    xml.Save("incomes.xml");
}

vector <Income> FileWithIncomes::loadIncomesFromFile(int loggedUserId)
{
    CMarkup xml;

    vector <Income> incomes;
    Income income;

    int incomeId = 0, userId = 0, dateInt = 0;
    string date = "", item = "", amount = "";

    xml.Load("incomes.xml");
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Income"))
    {
        xml.FindChildElem("UserId");
        userId = atoi(MCD_2PCSZ(xml.GetChildData()));

        if (loggedUserId == userId)
        {
            xml.ResetChildPos();

            xml.FindChildElem("IncomeId");
            incomeId = atoi(MCD_2PCSZ(xml.GetChildData()));
            income.setIncomeId(incomeId);

            income.setUserId(userId);

            xml.FindChildElem("Date");
            date = xml.GetChildData();
            //dateInt = operationsOnDates.conversionDateToInt(date);
            dateInt = OperationsOnDates::conversionDateToInt(date);
            income.setDate(dateInt);

            xml.FindChildElem("Item");
            item = xml.GetChildData();
            income.setItem(item);

            xml.FindChildElem("Amount");
            amount = xml.GetChildData();
            income.setAmount(amount);

            incomes.push_back(income);
        }
    }
    return incomes;
}

int FileWithIncomes::getIdOfTheLastIncomeFromFile()
{
    CMarkup xml;

    int lastIncomeId = 0;

    xml.Load("incomes.xml");
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Income"))
    {
        xml.FindChildElem("IncomeId");
        lastIncomeId = atoi(MCD_2PCSZ(xml.GetChildData()));
    }
    return lastIncomeId;
}
