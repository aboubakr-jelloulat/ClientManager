#include "../includes/clsBankClient.h"
#include "../includes/clsInputValidate.h"
#include "../includes/clsUtils.h"

#include "../includes/main.h"

void DeleteClient()
{
    cout << "\nEnter Account Number : ";
    string AccountNumber;  AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number is not found, choose another one : ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "Are you sure you want to delete this client y/n : ";
    char Answer;  cin >> Answer;

    if (tolower(Answer) == 'y')
    {
        if (Client1.Delete())
        {
            cout << endl << "Client Deleted Successfully " << endl;
            Client1.Print();
        }
        else
            cout << "Error Client was not Deleted" << endl;
    }
}
