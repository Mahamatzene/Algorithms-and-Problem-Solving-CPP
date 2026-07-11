#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

enum enPrimeOrNotPrime { Prime = 1, NotPrime = 2};

enPrimeOrNotPrime CheckPrime(int number)
{
    int m = round(number / 2);

    for (int counter = 2; counter <= m; counter++)
    {
        if (number % counter == 0)
        {
            return enPrimeOrNotPrime::NotPrime;
        }
    }

    return enPrimeOrNotPrime::Prime;
}

int RandomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "Enter the number of element\n";
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
}

void CopyOnlyPrimeNumbersInArray(int arrSoruce[100], int arrDestination[100], int arrLength, int& arr2Length)
{
    int counter = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if (CheckPrime(arrSoruce[i]) == enPrimeOrNotPrime::Prime)
        {
            arrDestination[counter] = arrSoruce[i];
            counter++;
        }
    }
    arr2Length = --counter;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength;

    FillArrayWithRandomNumbers(arr, arrLength);

    int arr2[100], arr2Length = 0;

    CopyOnlyPrimeNumbersInArray(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    cout << "\nPrime numbers in array2:\n";
    PrintArray(arr2, arr2Length);
    cout << endl;

    return 0;
}