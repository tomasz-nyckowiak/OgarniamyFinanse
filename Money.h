#ifndef MONEY_H
#define MONEY_H

#include <iostream>

#include "AuxiliaryMethods.h"

using namespace std;

class Money
{

public:

    bool checkingIfAmountIsCorrect(string enteredAmount);
    string enteringAmount();
    string replacingComaWithDot(string amount);
    float convertingAmountFromStringToFloat(string amount);
};

#endif
