#include "includes/clsBankClient.h"
#include "includes/main.h"

void ft_usage()
{
	std::cout << "\033[1;34m"
			  << "Usage:\n"
			  << "./Client Find \n"
			  << "./Client Add \n"
			  << "./Client Update \n"
			  << "./Client Delete\n"
			  << "./Client ShowClientList\n"
			  << "./Client ShowClientTotalBalance\n"
			  << "\033[0m";
}

int main(int ac, char **av)
{

	if (ac == 2)
	{
		if (string(av[1]) == "Find")
		{
			FindClient();
		}
		else if (string(av[1]) == "Add")
		{
			AddNewClient();
		}
		else if (string(av[1]) == "Update")
		{
			UpdateClient();
		}
		else if (string(av[1]) == "Delete")
		{
			DeleteClient();
		}
		else if (string(av[1]) == "ShowClientList")
		{
			ShowClientsList();
		}
		else if (string(av[1]) == "ShowClientTotalBalance")
		{
			ShowTotalBalances();
		}
		else
		{
			cout << "Invalid command!" << endl;
			ft_usage();
		}
	}
	else
	{
		cout << "Incorrect number of arguments!" << endl;
		ft_usage();
	}

	return 0;
}
