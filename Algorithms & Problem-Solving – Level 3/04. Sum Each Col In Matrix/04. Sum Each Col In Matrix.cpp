

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

int SumEachCol(int arr[3][3], short row, short colsNumber) {

    int sum = 0;

    for (short j = 0; j < row; j++) {
        sum += arr[j][colsNumber];
    }

    return sum;
}

void PrintEachColSum(int arr[3][3], short rows, short cols) {

    cout << "\nThe following are the sum of each column in the matrix\n";
    for (short i = 0; i < cols; i++) {

        cout << "Column " << i + 1 << " Sum = " << SumEachCol(arr, rows, i) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    GenerteMatrix(arr, 3, 3);
    PrintMatrix(arr, 3, 3);
    PrintEachColSum(arr, 3, 3);

    return 0;
}