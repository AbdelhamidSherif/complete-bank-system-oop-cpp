#pragma once
#include "clsScreen.h";
#include "clsBankClient.h";
#include <string>
#include "clsInputValidate.h";


class clsDeleteClientScreen :protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

public:
	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;// this will exit the function and it will not continue
		}

		clsScreen::_DrawScreenHeader("\t  Delete Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is Not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		char Answer = 'n';
		cout << "\nAre you sure you want to delete this client y/n? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			if (Client.Delete())
			{
				cout << "\nClient Deleted Successfully :-)\n";
				_PrintClient(Client);
			}
			else
			{
				cout << "\nError Client was not Deleted\n";
			}
		}
	}

};

