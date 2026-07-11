
#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int from, int to) {
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}

int ReadPositiveNumber() {
    int number = 0;

    do {
        cout << "\nPlease enter the number to look for in matrix : ";
        cin >> number;

    } while (number < 0);

    return number;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short row, short col) {
    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col; j++) {
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}

bool CheckNumberInMatrix(int arr[3][3], short row, short col) {

    int number = ReadPositiveNumber();

    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col; j++) {
            if (arr[i][j] == number) {
                return true;
            }
        }
    }

    return false;
}

void PrintMatrix(int arr[3][3], short row, short col) {

    cout << "Matrix 1 : \n";

    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int arr[3][3];

    FillMatrixWithRandomNumbers(arr, 3, 3);
    PrintMatrix(arr, 3, 3);

    if (CheckNumberInMatrix(arr, 3, 3))
        cout << "\nYes : it's there\n";
    else
        cout << "\nNo : it's NOT there\n";

    return 0;
}

