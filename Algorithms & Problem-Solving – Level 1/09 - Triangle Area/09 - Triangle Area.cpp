

#include <iostream>
using namespace std;

void readNumberes(int arr[3])
{
    cout << "please enter your number 1" << endl;
    cin >> arr[0];
    cout << "please enter your number 2" << endl;
    cin >> arr[1];
    cout << "please enter your number 3" << endl;
    cin >> arr[2];
}

int sumOfNumbers(int arr[3])
{
    return arr[0] + arr[1] + arr[2];
}

void printResult(int total)
{
    cout << "\n your total sum is : " << total << endl;
}

int main()
{
    int arr[3];
    readNumberes(arr);
    printResult(sumOfNumbers(arr));

    return 0;

}


