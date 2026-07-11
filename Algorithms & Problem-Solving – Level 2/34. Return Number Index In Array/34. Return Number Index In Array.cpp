

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int RandomeNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}

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

void FillArrayWithRandomKeys(int arr[100], int& arrLength)
{
    cout << "\nEnter  number of elements:\n";
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomeNumber(1, 100);
    }
}

void PrintArray(int arr[100], int arrLength)
{
    cout << "\nArray elements : \n";

    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

short FindNumberPositionInArray(int number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == number)
        {
            return i; //this will break the fonction and return the index
        }
    }

    //if you reached here, this means the number is not found
    return -1;
}

int ReadNumber()
{
    int number = 0;

    cout << "\nPlease enter a number to search for ?\n";
    cin >> number;

    return number;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength;
    FillArrayWithRandomKeys(arr, arrLength);

    PrintArray(arr, arrLength);

    int number = ReadNumber();
    cout << "\nNumber you are looking for is : " << number << endl;

    short numberPosition = FindNumberPositionInArray(number, arr, arrLength);

    if (numberPosition == -1)
        cout << "The number is not found :-(\n";
    else
    {
        cout << "The number is found at position : " << numberPosition << endl;;
        cout << "The number is found at order    : " << numberPosition + 1 << endl;
    }

    return 0;
}