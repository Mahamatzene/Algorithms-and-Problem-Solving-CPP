#include <iostream>
#include <cstdlib>
using namespace std;

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

int CheckMinNumber(int arr[100], int arrLength)
{
    int min = arr[0];

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];

        }
    }
    return min;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength, max;

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray element : ";
    PrintArray(arr, arrLength);

    cout << "\nMin number is : ";
    cout << CheckMinNumber(arr, arrLength) << endl;

    return 0;
}