
#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int from, int to) {
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short row, short col) {
    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col; j++) {
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}

void MultyTwoMatrices(int arr[3][3], int arr2[3][3], int arrMul[3][3], short row, short col) {
    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col; j++) {
            arrMul[i][j] = arr[i][j] * arr2[i][j];
        }
    }
}

void PrintMatrixElements(int arr[3][3], short row, short col) {
    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col; j++) {
            printf("%0*d\t", 2, arr[i][j]);
        }

        cout << endl;
    }

    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3], arr2[3][3], arrMul[3][3];

    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "Matrix 1 :" << endl;
    PrintMatrixElements(arr, 3, 3);

    FillMatrixWithRandomNumbers(arr2, 3, 3);
    cout << "Matrix 2 :" << endl;
    PrintMatrixElements(arr2, 3, 3);

    MultyTwoMatrices(arr, arr2, arrMul, 3, 3);
    cout << "Result :" << endl;
    PrintMatrixElements(arrMul, 3, 3);

    return 0;

}


