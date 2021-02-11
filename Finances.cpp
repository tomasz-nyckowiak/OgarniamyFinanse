#include "Finances.h"

void Finances::setUserId(int newUserId)
{
    userId = newUserId;
}
void Finances::setDate(int newDate)
{
    date = newDate;
}
void Finances::setItem(string newItem)
{
    item = newItem;
}
void Finances::setAmount(string newAmount)
{
    amount = newAmount;
}

int Finances::getUserId()
{
    return userId;
}
int Finances::getDate()
{
    return date;
}
string Finances::getItem()
{
    return item;
}
string Finances::getAmount()
{
    return amount;
}
