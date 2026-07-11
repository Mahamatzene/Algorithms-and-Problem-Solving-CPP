

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int RandomNumbers(int from, int to) {
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}

void GenerteMatrix(int arr[3][3], short rows, short cols) {


    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            arr[i][j] = RandomNumbers(1, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], short rows, short cols) {


    cout << "\nThe following is a 3x3 random matrix :" << endl;

    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {

            cout << left << setw(3) << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int SumEachCol(int arr[3][3], short rows, short colNumber) {

    int sum = 0;

    for (short j = 0; j < rows; j++) {
        sum += arr[j][colNumber];
    }

    return sum;
}

void SumMatixColsInArry(int arr[3][3], int arrSum[3], short Rows, short Cols) {

    for (short i = 0; i < Rows; i++) {

        arrSum[i] = SumEachCol(arr, Rows, i);

    }
}

void PrintEachColSumArray(int arr[3], short cols) {

    cout << "\nThe following are the sum of each col in the matrix\n";
    for (short i = 0; i < cols; i++) {

        cout << "Col " << i + 1 << " Sum = " << arr[i] << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];
    int arrSum[3];

    GenerteMatrix(arr, 3, 3);
    PrintMatrix(arr, 3, 3);
    SumMatixColsInArry(arr, arrSum, 3, 3);
    PrintEachColSumArray(arrSum, 3);

    return 0;
}