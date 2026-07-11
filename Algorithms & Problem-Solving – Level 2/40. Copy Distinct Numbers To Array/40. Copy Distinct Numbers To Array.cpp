
#include <iostream>
using namespace std;

void FillArray(int arr[10], int& arrLength)
{
    arrLength = 10;

    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
    
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n";
}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i;  // Return the index as soon as the number is found.
    }
    // If the number is not found, return -1.
    return -1;
}

bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}

void AddArrayElements(int number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = number;
}

void CopyOnlyDistinctNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (!IsNumberInArray(arrSource[i], arrDestination, arrDestinationLength))
        {
            AddArrayElements(arrSource[i], arrDestination, arrDestinationLength);
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[10], arrLength;

    FillArray(arr, arrLength);

    int arr2[10], arr2Length = 0;

    CopyOnlyDistinctNumbers(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 elements :\n";
    PrintArray(arr, arrLength);

    cout << "\nArray 2 distinct numbers :\n";
    PrintArray(arr2, arr2Length);

    return 0;
}