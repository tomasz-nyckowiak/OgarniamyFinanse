#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"
#include "OperationsOnDates.h"

using namespace std;

class FileWithIncomes : public XmlFile
{

public:
    FileWithIncomes(string nameOfTheFileWithIncomes) : XmlFile(nameOfTheFileWithIncomes) {};

    void addIncomeToFile(Income income);
    vector <Income> loadIncomesFromFile(int loggedUserId);
    int getIdOfTheLastIncomeFromFile();
};

#endif
