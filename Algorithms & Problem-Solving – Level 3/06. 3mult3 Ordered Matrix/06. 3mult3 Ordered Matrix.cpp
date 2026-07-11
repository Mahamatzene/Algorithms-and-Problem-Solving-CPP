

#include <iostream>
#include <iomanip>
using namespace std;

void FillMatrixWithOrderedNumbers(int arr[3][3], short rows, short cols) {
    short orderedNum = 0;

    for (short i = 0; i < rows; ++i) {
        for (short j = 0; j < cols; ++j) {
            orderedNum++;
            arr[i][j] = orderedNum;
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

int main()
{
    int arr[3][3];

    FillMatrixWithOrderedNumbers(arr, 3, 3);
    PrintMatrix(arr, 3, 3);

    return 0;
}