
#include <iostream>
#include <cstdlib>
using namespace std;

void PrintMatrix(int arr[3][3], short row, short col) {

    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

bool IsNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] == Number)
            {
                return true;
            }
        }
    }
    return false;
}

void PrintIntersectedNUmbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols) {
    int number = 0;

    for (short i = 0; i < Rows; i++){
        for (short j = 0; j < Cols; j++) {
            number = Matrix1[i][j];

            if (IsNumberInMatrix(Matrix2, number, Rows, Cols)) {
                cout << number << "\t";
            }
        }
    }

}

int main()
{
    int arr3[3][3] = { {77, 5, 12}, {22, 20, 1}, {1, 0, 9} };
    int arr4[3][3] = { {5, 80, 90}, {22, 77, 1}, {10, 8, 3} };

    cout << "Matrix 1 : \n";
    PrintMatrix(arr3, 3, 3);

    cout << "Matrix 2 : \n";
    PrintMatrix(arr4, 3, 3);

    cout << "\nIntersected numbers are :\n";
    PrintIntersectedNUmbers(arr3, arr4, 3, 3);

    return 0;
}

