
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

void PrintMatrixElements(int arr[3][3], short row, short col) {
    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col; j++) {
            printf("%0*d\t", 2, arr[i][j]);
        }

        cout << endl;
    }
}

int SumOfMatrix(int arr[3][3], short row, short col) {
    int sum = 0;

    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col; j++) {
            sum += arr[i][j];
        }
    }

    return sum;
}

bool IsEqual(int arr[3][3], int arr2[3][3], short row, short col) {

    return (SumOfMatrix(arr, row, col) == SumOfMatrix(arr2, row, col));
    
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3], arr2[3][3];

    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "Matrix 1 :\n";
    PrintMatrixElements(arr, 3, 3);

    FillMatrixWithRandomNumbers(arr2, 3, 3);
    cout << "\nMatrix 2 :\n";
    PrintMatrixElements(arr2, 3, 3);

    SumOfMatrix(arr, 3, 3);

    if (IsEqual(arr, arr2, 3, 3)) {
        cout << "\nYes: matracis are equal\n";
    }
    else {
        cout << "\nNo: matracis are NOT equal\n";
    }
        
    return 0;

}