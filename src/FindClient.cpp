#include "../includes/clsBankClient.h"
#include "../includes/clsInputValidate.h"
#include "../includes/clsUtils.h"

#include "../includes/main.h"

void FindClient()
{
    string AccountNumber;

    cout << "Enter Account number :" << endl;
    AccountNumber = clsInputValidate::ReadString();

    clsBankClient   Client1 = clsBankClient::Find(AccountNumber);
    if (!Client1.IsEmpty())
    {
        cout << endl << "Client is found " << endl;
    }
    else
    {
        cout << endl << "Client was not found " << endl;
    }
    Client1.Print();
}
