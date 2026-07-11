

#include <iostream>
using namespace std;

struct stPiggyBankContenet
{
	int pennies, nickels, dimes, quarters, dollars;
};

stPiggyBankContenet ReadPiggyBankContenet()
{
	stPiggyBankContenet PiggyBankContenet;

	cout << "please enter a total pennies" << endl;
	cin >> PiggyBankContenet.pennies;
	cout << "please enter a total nickels" << endl;
	cin >> PiggyBankContenet.nickels;
	cout << "please enter a total dimes" << endl;
	cin >> PiggyBankContenet.dimes;
	cout << "please enter a total quarters" << endl;
	cin >> PiggyBankContenet.quarters;
	cout << "please enter a total dollars" << endl;
	cin >> PiggyBankContenet.dollars;

	return PiggyBankContenet;
}

int CalculateTotalPennies(stPiggyBankContenet PiggyBankContenet)
{
	int totalPennies = 0;

	totalPennies = PiggyBankContenet.pennies * 1 + PiggyBankContenet.nickels * 5 + PiggyBankContenet.dimes * 10 +
		PiggyBankContenet.quarters * 25 + PiggyBankContenet.dollars * 100;

	return totalPennies;
}

int main()
{
	int totalPennies = CalculateTotalPennies(ReadPiggyBankContenet());

	cout << endl << "total pennies = " << totalPennies << endl;
	cout << endl << "total dollars = " << (float)totalPennies / 100 << endl;

	return 0;
}