#include "../includes/clsBankClient.h"
#include "../includes/clsInputValidate.h"
#include "../includes/clsUtils.h"

#include "../includes/main.h"

void PrintClientRecordBalanceLine(clsBankClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber()
    << "| " << setw(40) << left << Client.FullName()
    << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowTotalBalances()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();
    double TotalBalances;

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n________________________________________________________________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n________________________________________________________________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else
        for (clsBankClient Client : vClients)
        {
            PrintClientRecordBalanceLine(Client); 
            cout << endl;
        }
    cout << "\n________________________________________________________________________________________________\n" << endl;

    TotalBalances = clsBankClient::GetTotalBalances();
    cout << "\t\t\t\t💰 Total Balances = " << TotalBalances << " 💵" << endl;
    cout << "\t\t\t\t🔢 In Words: " << clsUtils::NumberToText(TotalBalances) << " 📝" << endl;
}
