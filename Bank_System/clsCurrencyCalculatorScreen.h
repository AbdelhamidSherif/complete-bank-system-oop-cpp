#pragma once
#include "clsScreen.h"
#include "clsString.h"
#include <string>

using namespace std;

class clsCurrencyCalculatorScreen :protected clsScreen
{

#pragma region Another Solution

	//private:
	//	static float _ReadAmount()
	//	{
	//		cout << "\nEnter Amount to Exchange: ";
	//		float Amount = 0;
	//
	//		Amount = clsInputValidate::ReadFloatNumber();
	//		return Amount;
	//	}
	//
	//	/*static void _PrintCurrency(clsCurrency Currency)
	//	{
	//		cout << "\nCurrency Card:\n";
	//		cout << "_____________________________\n";
	//		cout << "\nCountry    : " << Currency.Country();
	//		cout << "\nCode       : " << Currency.CurrencyCode();
	//		cout << "\nName       : " << Currency.CurrencyName();
	//		cout << "\nRate(1$) = : " << Currency.Rate();
	//
	//		cout << "\n_____________________________\n";
	//
	//	}*/
	//
	//	static void _PrintCurrency(clsCurrency Currency,string Message)
	//	{
	//		cout << "\n" << Message << ":\n";
	//		cout << "_____________________________\n";
	//		cout << "\nCountry    : " << Currency.Country();
	//		cout << "\nCode       : " << Currency.CurrencyCode();
	//		cout << "\nName       : " << Currency.CurrencyName();
	//		cout << "\nRate(1$) = : " << Currency.Rate();
	//
	//		cout << "\n_____________________________\n";
	//
	//	}
	//
	//	static void _CalculateExchange(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	//	{
	//		float Result = 0;
	//
	//		if (CurrencyFrom.CurrencyCode() == "USD")
	//		{
	//			
	//			Result = Amount * CurrencyTo.Rate();
	//
	//			cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode()
	//				<< " = " << Result << " " << CurrencyTo.CurrencyCode() << endl;
	//		}
	//		else if (CurrencyTo.CurrencyCode() == "USD")
	//		{
	//			Result = Amount / CurrencyFrom.Rate();
	//			cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode()
	//				<< " = " << Result << " " << CurrencyTo.CurrencyCode() << endl;
	//		}
	//		else
	//		{
	//			float ToInUsd = Amount / CurrencyFrom.Rate();
	//			cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode()
	//				<< " = " << ToInUsd << " USD " << endl;
	//			
	//
	//			float ToInOther = ToInUsd * CurrencyTo.Rate();
	//
	//			cout << "\nConverting from USD to:\n";
	//			_PrintCurrency(CurrencyTo,"To: ");
	//
	//			cout << "\n" << Amount << " USD "
	//				<< " = " << ToInOther << " " << CurrencyTo.CurrencyCode() << endl;
	//		}
	//
	//	}
	//
	//
	//public:
	//
	//	static void ShowCurrencyCalculatorScreen()
	//	{
	//
	//		char Choice = 'n';
	//
	//		do
	//		{
	//			_DrawScreenHeader("\tCurrency Calculator Screen");
	//
	//			cout << "\nPlease Enter Currency1 Code: ";
	//			string CurrencyCode_1 = clsInputValidate::ReadString();
	//
	//			while (!clsCurrency::IsCurrencyExist(CurrencyCode_1))
	//			{
	//				cout << "\nCurrency is not found, choose another one: ";
	//				CurrencyCode_1 = clsInputValidate::ReadString();
	//			}
	//
	//			cout << "\nPlease Enter Currency2 Code: ";
	//			string CurrencyCode_2 = clsInputValidate::ReadString();
	//
	//			while (!clsCurrency::IsCurrencyExist(CurrencyCode_2) || CurrencyCode_1 == CurrencyCode_2)
	//			{
	//				cout << "\nCurrency is not found or same Currency Code One, choose another one: ";
	//				CurrencyCode_2 = clsInputValidate::ReadString();
	//			}
	//
	//			float Amount = _ReadAmount();
	//
	//			clsCurrency CurrencyFrom = clsCurrency::FindByCode(CurrencyCode_1);
	//			clsCurrency CurrencyTo = clsCurrency::FindByCode(CurrencyCode_2);
	//
	//			_PrintCurrency(CurrencyFrom,"Convert From:");
	//
	//			_CalculateExchange(Amount, CurrencyFrom, CurrencyTo);
	//
	//			cout << "\nDo you want to perform another calculation? y/n ? ";
	//			cin >> Choice;
	//			if (Choice == 'y' || Choice == 'Y')
	//			{
	//				system("cls");
	//			}
	//		} while (Choice =='y'||Choice =='Y');
	//
	//	}

#pragma endregion


private:

	static float _ReadAmount()
	{
		cout << "\nEnter Amount to Exchange: ";
		float Amount = 0;

		Amount = clsInputValidate::ReadFloatNumber();
		return Amount;
	}

	static clsCurrency _GetCurrency(string Message)
	{

		string CurrencyCode;
		//cout << Message << endl;
		cout << Message;

		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;

	}

	static  void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
	{

		cout << "\n" << Title << "\n";
		cout << "_____________________________\n";
		cout << "\nCountry       : " << Currency.Country();
		cout << "\nCode          : " << Currency.CurrencyCode();
		cout << "\nName          : " << Currency.CurrencyName();
		cout << "\nRate(1$) =    : " << Currency.Rate();
		cout << "\n_____________________________\n\n";

	}


	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{

		_PrintCurrencyCard(Currency1, "Convert From:");

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD to:\n";

		_PrintCurrencyCard(Currency2, "To:");

		float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();

	}


public:
	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'y';

		while (Continue == 'y' || Continue == 'Y')
		{
			system("cls");

			_DrawScreenHeader("\tUpdate Currency Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");

			while (CurrencyFrom.CurrencyCode() == CurrencyTo.CurrencyCode())
			{
				CurrencyTo = _GetCurrency("\nCurrency One is the same Currency Two, choose another one: ");
			}
			float Amount = _ReadAmount();

			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want to perform another calculation? y/n ? ";
			cin >> Continue;
		}
	}
};

