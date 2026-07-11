#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int from, int to)
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

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
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

    cout << "\n";
}

void Sum2OfArrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arrSum[i] = arr1[i] + arr2[i];
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr1[100], arr2[100], arrSum[100];

    int arrLength = ReadPositiveNumber("plese enter how many elements you wand ?");

    FillArrayWithRandomNumbers(arr1, arrLength);
    FillArrayWithRandomNumbers(arr2, arrLength);

    Sum2OfArrays(arr1, arr2, arrSum, arrLength);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr1, arrLength);

    cout << "\nArray 2 elements:\n";
    PrintArray(arr2, arrLength);
    
    cout << "\nSum of array1 and array2:\n";
    PrintArray(arrSum, arrLength);

    return 0;
}