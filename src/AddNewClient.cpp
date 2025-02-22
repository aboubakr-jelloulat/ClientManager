#include "../includes/clsBankClient.h"
#include "../includes/clsInputValidate.h"
#include "../includes/clsUtils.h"

#include "../includes/main.h"

static void ReadClientInfo(clsBankClient& Client)
{
    cout << "\nEnter FirstName: ";
    Client.FirstName = clsInputValidate::ReadString();

    cout << "\nEnter LastName: ";
    Client.LastName = clsInputValidate::ReadString();

    cout << "\nEnter Email: ";
    Client.Email = clsInputValidate::ReadString();

    cout << "\nEnter Phone: ";
    Client.Phone = clsInputValidate::ReadString();

    cout << "\nEnter Password : ";
    Client.PinCode = clsInputValidate::ReadString();

    cout << "\nEnter Account Balance: ";
    Client.AccountBalance = clsInputValidate::ReadFloatNumber();
}

void AddNewClient()
{
    string AccountNumber = "";

    cout << endl << "Please Enter Account Number : ";
    AccountNumber = clsInputValidate::ReadString();
    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number is Already Used, Choose another one : ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient   NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

    ReadClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResult;
    SaveResult = NewClient.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded :
    {
        cout << endl << "Account Added Successfully " << endl;
        NewClient.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject :
    {
        cout << endl << "Error account was not saved because it;s Empty" << endl;
        break;
    }
    case clsBankClient::enSaveResults::svFaildAccountNumberExists :
    {
        cout << endl << "Error account was not saved because account number is Alrady used !!" << endl;
        break;
    }
    }
}
