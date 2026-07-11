
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

void PrintRowElements(int arr[3][3], short row, short col) {

    short middleRow = row / 2;

    for (short i = 0; i < col; i++) {

        printf("%0*d\t", 2, arr[middleRow][i]);
    }

    cout << endl;
}

void PrintColElemetns(int arr[3][3], short row, short col) {

    short middleCol = col / 2;

    for (short i = 0; i < row; i++) {

        printf("%0*d\t", 2, arr[i][middleCol]);
    }

    cout << endl;
}

void PrintMatrixElements(int arr[3][3], short row, short col) {
    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col; j++) {
            printf("%0*d\t", 2, arr[i][j]);
        }

        cout << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "Matrix 1 :\n";
    PrintMatrixElements(arr, 3, 3);

    cout << "\nMiddle row of matrix is :\n";
    PrintRowElements(arr, 3, 3);

    cout << "\nMiddle column of matrix is :\n";
    PrintColElemetns(arr, 3, 3);

    return 0;

}