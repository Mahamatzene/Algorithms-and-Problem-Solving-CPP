

#include <iostream>
#include <string>
using namespace std;

void enterYourNumber(int &n1, int &n2)
{
	cout << "please enter the number1 ?" << endl;
	cin >> n1;
	cout << "please enter the number2 ?" << endl;
	cin >> n2;
}

void Swap(int &A, int &B)
{
	int temp;
	temp = A;
	A = B;
	B = temp;
	

}

void PrintNumbers(int num1, int num2)
{
	cout << "\n the number 1 is : " << num1 << endl;
	cout << "\n the number 2 is : " << num2 << endl;
}
int main()
{
	int n1, n2;
	enterYourNumber(n1, n2);
	PrintNumbers(n1, n2);
	cout << "\n****************\n";
	Swap(n1, n2);
	PrintNumbers(n1, n2);
	

	return 0;
}