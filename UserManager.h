#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "FileWithUsers.h"
#include "XmlFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User giveInformationAboutNewUser();
    int getIdOfTheNewUser();
    bool isLoginExists(string login);

public:
    UserManager(string nameOfTheFileWithUsers) : fileWithUsers(nameOfTheFileWithUsers)
    {
        loggedUserId = 0;
        users = fileWithUsers.loadUsersFromFile();
    };

    void userRegistering();
    void userLoggingIn();
    void changePasswordOfTheLoggedUser();
    void userLoggingOut();
    bool isUserLoggedIn();
    int getIdOfTheLoggedUser();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
};

#endif
