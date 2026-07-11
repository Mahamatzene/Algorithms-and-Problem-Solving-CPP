

#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber(string message)
{
    int number = 0;

    do
    {
        cout << message << endl;
        cin >> number;

    } while (number <= 0);

    return number;
}

void ReadArray(int arr[100], int &arrLength)
{
    cout << "Enter the number of elements\n";
    cin >> arrLength;

    cout << "\nEnter the element\n";

    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element [" << i + 1 << "] :";
        cin >> arr[i];
    }
    cout << endl;
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int TimesRepeted(int number, int arr[100], int arrLength)
{
    int count = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if (number == arr[i])
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int arr[100];
    int arrLength;
    int numberToCheck;

    ReadArray(arr, arrLength);

    numberToCheck = ReadPositiveNumber("Enter the number you want to check");

    cout << "\nOriginal number : ";
    PrintArray(arr, arrLength);

    cout << numberToCheck;
    cout << " is repeted ";
    cout << TimesRepeted(numberToCheck, arr, arrLength) << " time(s)\n";

    return 0;

}