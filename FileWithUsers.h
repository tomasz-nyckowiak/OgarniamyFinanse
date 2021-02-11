#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"

using namespace std;

class FileWithUsers : public XmlFile
{

public:
    FileWithUsers(string nameOfTheFileWithUsers) : XmlFile(nameOfTheFileWithUsers) {};

    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void savingChangedPasswordToFile(string newPassword, string oldPassword);
};

#endif
