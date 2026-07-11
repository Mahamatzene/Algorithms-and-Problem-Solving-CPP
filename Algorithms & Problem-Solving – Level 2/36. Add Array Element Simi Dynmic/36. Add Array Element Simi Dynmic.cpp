
#include <iostream>
#include <string>
using namespace std;

int ReadNumber()
{
    int number;

    
        cout << "\nPlease enter a number ? " << endl;
        cin >> number;

    return number;
}

void AddArrayElements(int number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = number;
}

void InputUserNumbersInArrray(int arr[100], int& arrLength)
{
    bool addMore = true;

    do
    {
        AddArrayElements(ReadNumber(), arr, arrLength);

        cout << "\nDo you want to add more number? [0] No, [1] Yes : ";
        cin >> addMore;

    } while (addMore);
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[100], arrLength = 0;

    InputUserNumbersInArrray(arr, arrLength);

    cout << "\nArray length : " << arrLength;
    cout << "\nArray elements :";
    PrintArray(arr, arrLength);

    return 0;
}

