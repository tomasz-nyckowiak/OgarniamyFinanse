#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

#include "Markup.h"

using namespace std;

class XmlFile
{
    const string NAME_OF_THE_FILE;

public:
    XmlFile(string nameOfTheFile) : NAME_OF_THE_FILE(nameOfTheFile) {}

    string getNameOfTheFile();
};

#endif
