

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int RandomeNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
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

bool IsNumberInArray(int number, int arr[100], int arrLength)
{
    return FindNumberPositionInArray(number, arr, arrLength) != -1;
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

    short check = IsNumberInArray(number, arr, arrLength);

    if (!IsNumberInArray(number, arr, arrLength))
        cout << "No, The number is not found :-(\n";
    else
    {
        cout << "Yes, the number is found :-)\n";
    }

    return 0;
}