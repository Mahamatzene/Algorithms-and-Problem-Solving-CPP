
#include <iostream>
using namespace std;

void PrintMatrix(int arr[3][3], short row, short col) {

    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int MinNumberInMatrix(int arr[3][3], short row, short col) {
    int min = arr[0][0];

    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col; j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }

    return min;
}

int MaxNumberInMatrix(int arr[3][3], short row, short col) {
    int max = arr[0][0];

    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }

    return max;
}

int main()
{
    int arr3[3][3] = { {77, 5, 12}, {22, 20, 6}, {14, 3, 9} };

    cout << "Matrix 1 : \n";
    PrintMatrix(arr3, 3, 3);


    cout << "\nMax number is : ";
    cout << MaxNumberInMatrix(arr3, 3, 3) << endl;

    cout << "\nMin number is : ";
    cout << MinNumberInMatrix(arr3, 3, 3) << endl;
    return 0;
}

