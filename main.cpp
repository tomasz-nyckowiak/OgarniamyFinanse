#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");

    while (true)
    {
        if (personalBudget.isUserLoggedIn() == false)
        {
            switch (personalBudget.chooseOptionFromMainMenu())
            {
            case '1':
                personalBudget.userRegistering();
                break;
            case '2':
                personalBudget.userLoggingIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            switch (personalBudget.chooseOptionFromUserMenu())
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.balanceSheetForTheCurrentMonth();
                break;
            case '4':
                personalBudget.balanceSheetForThePreviousMonth();
                break;
            case '5':
                personalBudget.balanceSheetForTheChosenPeriod();
                break;
            case '6':
                personalBudget.changePasswordOfTheLoggedUser();
                break;
            case '7':
                personalBudget.userLoggingOut();
                break;
            }
        }
    }
    return 0;
}
