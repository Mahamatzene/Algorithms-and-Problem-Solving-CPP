
#include <iostream>
#include <cstdlib>
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
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n";
}

int EvenCount(int arr[100], int arrLength)
{
    int counter = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] % 2 == 0)
        {
            counter++;
        }
    }

    return counter;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength;

    FillArrayWithRandomKeys(arr, arrLength);

    cout << "\nArray 1 elements :\n";
    PrintArray(arr, arrLength);

    cout << "\nEven numbers count is : ";
    cout << EvenCount(arr, arrLength) << endl;


    return 0;
}
