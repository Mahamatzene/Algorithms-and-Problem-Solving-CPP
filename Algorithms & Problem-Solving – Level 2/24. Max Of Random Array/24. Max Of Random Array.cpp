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

int CheckMaxNumber(int arr[100], int arrLength)
{
    int max = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            
        }
    }
    return max;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength, max;

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray element : ";
    PrintArray(arr, arrLength);

    cout << "\nMax number is : ";
    cout << CheckMaxNumber(arr, arrLength) << endl;

    return 0;
}