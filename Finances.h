#ifndef FINANCES_H
#define FINANCES_H

#include <iostream>

using namespace std;

class Finances
{
    int userId;
    int date;
    string item;
    string amount;

public:
    Finances(int userId = 0, int date = 0, string item = "", string amount = "")
    {
        this -> userId = userId;
        this -> date = date;
        this -> item = item;
        this -> amount = amount;
    }

    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getUserId();
    int getDate();
    string getItem();
    string getAmount();

    bool operator < (const Finances &str) const
    {
        return (date < str.date);
    }
};

#endif
