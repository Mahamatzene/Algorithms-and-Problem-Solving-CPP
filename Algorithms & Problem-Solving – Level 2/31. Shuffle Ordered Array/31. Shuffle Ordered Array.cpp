#include <iostream>
#include <cstdlib>
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

void Swap(int& a, int& b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = i + 1;
    }
}

int RandomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n";
}

void ShuffleArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr1[100];

    int arrLength = ReadPositiveNumber("plese enter how many elements you wand ?");

    FillArrayWithRandomNumbers(arr1, arrLength);

    cout << "\nArray elements before shufle:\n";
    PrintArray(arr1, arrLength);

    ShuffleArray(arr1, arrLength);

    cout << "\nArray elements after shufle:\n";
    PrintArray(arr1, arrLength);

    return 0;
}