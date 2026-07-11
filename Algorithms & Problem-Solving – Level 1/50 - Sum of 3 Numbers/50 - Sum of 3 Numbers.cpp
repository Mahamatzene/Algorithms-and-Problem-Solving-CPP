
#include <iostream>
#include <string>
using namespace std;

string ReadPinCode()
{
	string pinCode;

	cout << "please enter your PIN code\n";
	cin >> pinCode;

	return pinCode;
}

bool Login()
{
	string pinCode;
	int counter = 3;

	do
	{
		counter--;
		pinCode = ReadPinCode();

		if (pinCode == "1234")
		{
			return 1;
		}
		else
		{
			system("color 4F");
			cout << "wrong PIN, you have " << counter << " more tries" << endl;
		}
	} while (counter >= 1 && pinCode != "1234");

	return 0;
	
}

int main()
{
	if (Login())
	{
		system("color 6F");
		cout << "\n***************************\n";
		cout << "your balnace is: " << 7500 << endl;
		cout << "***************************\n";
	}
	else
	{
		cout << "\nyour card is blocke Call the bank for help\n";
	}

	return 0;
}

