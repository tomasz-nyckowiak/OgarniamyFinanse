#include "AuxiliaryMethods.h"

string AuxiliaryMethods::conversionIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

char AuxiliaryMethods::loadSign()
{
    string entry = "";
    char sign = {0};

    while (true)
    {
        getline(cin, entry);

        if (entry.length() == 1)
        {
            sign = entry[0];
            break;
        }
        else if (entry.length() > 1)
            cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

string AuxiliaryMethods::loadLine()
{
    string entry = "";
    getline(cin, entry);
    return entry;
}

int AuxiliaryMethods::conversionStringToInt(string number)
{
    int numberAsInt;
    istringstream iss(number);
    iss >> numberAsInt;
    return numberAsInt;
}

int AuxiliaryMethods::loadInteger()
{
    string entry = "";
    int number = 0;

    while (true)
    {
        getline(cin, entry);

        stringstream myStream(entry);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

bool AuxiliaryMethods::isSignANumber(string dateAsString)
{
    bool isANumber = true;

    for (int i = 0; i < dateAsString.length(); i++)
    {
        if (!isdigit(dateAsString[i]))
        {
            isANumber = false;
            return isANumber;
        }
    }
    return isANumber;
}
