#include <iostream> 
using namespace std;

int main()
{

	float a, b;
	const float PI = 3.14;

	cout << "Please enter the number a:";
	cin >> a;
	cout << "Please enter the number b:";
	cin >> b;

	float Area = (PI * (b * b / 4)) * ((2 * a - b) / (2 * a + b));
	cout << Area;


}