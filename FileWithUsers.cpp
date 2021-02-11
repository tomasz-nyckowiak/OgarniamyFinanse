#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xml;

    bool fileExists = xml.Load("users.xml");

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.Save("users.xml");
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    CMarkup xml;

    vector <User> users;
    User user;

    int userId = 0;
    string name = "", surname = "", login = "", password = "";

    xml.Load("users.xml");
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("User"))
    {
        xml.FindChildElem("UserId");
        userId = atoi(MCD_2PCSZ(xml.GetChildData()));
        user.setUserId(userId);

        xml.FindChildElem("Name");
        name = xml.GetChildData();
        user.setName(name);

        xml.FindChildElem("Surname");
        surname = xml.GetChildData();
        user.setSurname(surname);

        xml.FindChildElem("Login");
        login = xml.GetChildData();
        user.setLogin(login);

        xml.FindChildElem("Password");
        password = xml.GetChildData();
        user.setPassword(password);

        users.push_back(user);
    }
    return users;
}

void FileWithUsers::savingChangedPasswordToFile(string newPassword, string oldPassword)
{
    CMarkup xml;

    xml.Load("users.xml");
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("User"))
    {
        xml.FindChildElem("Password");

        if (xml.GetChildData() == oldPassword)
        {
            xml.SetChildData(newPassword);
            xml.Save("users.xml");
            break;
        }
    }
}
