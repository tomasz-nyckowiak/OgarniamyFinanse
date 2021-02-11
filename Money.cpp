#include "Money.h"

bool Money::checkingIfAmountIsCorrect(string enteredAmount)
{
    string signsBeforeDot = "", signsAfterDot = "", mergedSigns = "";
    int amountsLength = enteredAmount.length();
    int signsLengthAfterDot = 0;
    int counter = 0, nonDigitCounter = 0;
    int signPosition = 0, positionOfTheNonDigit = 0;
    char allowedSigns[2] = {'.', ','};
    bool isAmountCorrect = true;

    for (int i = 0; i < amountsLength; i++)
    {
        if (!isdigit(enteredAmount[counter]))
        {
            nonDigitCounter++;
            counter++;
            positionOfTheNonDigit = signPosition;
        }
        else
        {
            counter++;
            signPosition++;
        }
    }

    signsBeforeDot = enteredAmount.substr(0, positionOfTheNonDigit);
    signsAfterDot = enteredAmount.substr((positionOfTheNonDigit + 1), (counter - positionOfTheNonDigit) - 1);
    signsLengthAfterDot = signsAfterDot.length();

    if (nonDigitCounter > 1)
    {
        isAmountCorrect = false;
        return isAmountCorrect;
    }
    else if (nonDigitCounter == 1)
    {
        if (enteredAmount[positionOfTheNonDigit] != allowedSigns[0])
        {
            if (enteredAmount[positionOfTheNonDigit] != allowedSigns[1])
            {
                isAmountCorrect = false;
                return isAmountCorrect;
            }
            else
            {
                if (signsLengthAfterDot > 2)
                {
                    isAmountCorrect = false;
                    return isAmountCorrect;
                }
                else
                {
                    return isAmountCorrect;
                }
            }
        }
        else
        {
            if (signsLengthAfterDot > 2)
            {
                isAmountCorrect = false;
                return isAmountCorrect;
            }
            else
            {
                return isAmountCorrect;
            }
        }
    }
    else
    {
        return isAmountCorrect;
    }
}

string Money::enteringAmount()
{
    string amount = "";

    while (true)
    {
        cout << "Podaj kwote: ";
        amount = AuxiliaryMethods::loadLine();

        if (checkingIfAmountIsCorrect(amount) == false)
        {
            cout << "Wprowadzono bledna kwote! Sprobuj jeszcze raz." << endl;
        }
        else
        {
            break;
        }
    }

    amount = replacingComaWithDot(amount);
    return amount;
}

float Money::convertingAmountFromStringToFloat(string amount)
{
    string signsBeforeDot = "", signsAfterDot = "", mergedSigns = "";
    int amountsLength = amount.length();
    int signsLengthAfterDot = 0;
    int counter = 0, nonDigitCounter = 0;
    int amountAfterConversion = 0, amountAsInt = 0;
    int signPosition = 0, positionOfTheNonDigit = 0;
    float ourAmount = 0;

    for (int i = 0; i < amountsLength; i++)
    {
        if (!isdigit(amount[counter]))
        {
            nonDigitCounter = 1;
            counter++;
            positionOfTheNonDigit = signPosition;
        }
        else
        {
            counter++;
            signPosition++;
        }
    }

    signsBeforeDot = amount.substr(0, positionOfTheNonDigit);
    signsAfterDot = amount.substr((positionOfTheNonDigit + 1), (counter - positionOfTheNonDigit) - 1);
    signsLengthAfterDot = signsAfterDot.length();

    if (nonDigitCounter == 1)
    {
        if (amount[positionOfTheNonDigit] == ',')
        {
            amount[positionOfTheNonDigit] = '.';
        }

        mergedSigns = signsBeforeDot + signsAfterDot;
        amountAsInt = AuxiliaryMethods::conversionStringToInt(mergedSigns);

        if (signsLengthAfterDot == 2)
        {
            ourAmount = float(amountAsInt) / float(100);
            return ourAmount;
        }
        else
        {
            ourAmount = float(amountAsInt) / float(10);
            return ourAmount;
        }
    }
    else
    {
        amountAfterConversion = AuxiliaryMethods::conversionStringToInt(amount);
        ourAmount = float(amountAfterConversion);
        return ourAmount;
    }
}

string Money::replacingComaWithDot(string amount)
{
    int amountsLength = amount.length();

    for (int i = 0; i < amountsLength; i++)
    {
        if (amount[i] == ',')
        {
            amount[i] = '.';
            break;
        }
    }
    return amount;
}
