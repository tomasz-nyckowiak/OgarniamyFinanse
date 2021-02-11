#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"
#include "OperationsOnDates.h"

using namespace std;

class FileWithExpenses : public XmlFile
{

public:
    FileWithExpenses(string nameOfTheFileWithExpenses) : XmlFile(nameOfTheFileWithExpenses) {};

    void addExpenseToFile(Expense expense);
    vector <Expense> loadExpensesFromFile(int loggedUserId);
    int getIdOfTheLastExpenseFromFile();
};

#endif
