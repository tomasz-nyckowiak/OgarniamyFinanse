#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

class AuxiliaryMethods
{
public:
    static string conversionIntToString(int number);
    static string loadLine();
    static int conversionStringToInt(string number);
    static int loadInteger();
    static char loadSign();
    static bool isSignANumber(string dateAsString);
};

#endif
