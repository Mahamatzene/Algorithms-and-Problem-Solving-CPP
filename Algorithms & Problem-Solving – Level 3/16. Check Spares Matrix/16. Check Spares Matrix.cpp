
#include <iostream>
#include <iomanip>
using namespace std;

short CountNumberInMatrix(int arr[3][3], int number, short rows, short cols) {

    short counter = 0;

    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            if (arr[i][j] == number) {
                counter++;
            }
        }
    }

    return counter;
}

bool IsSparesMatrix(int arr[3][3], short row, short col) {
    short matrixSize = row * col;

    return (CountNumberInMatrix(arr, 0, 3, 3) >= (matrixSize / 2));
}

void PrintMatrix(int arr[3][3], short rows, short cols) {

    cout << "Matrix 1 : \n";

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";

        }
        cout << "\n";
    }
}

int main()
{
    int arr[3][3] = { {0, 0, 12},{0, 0, 9},{0, 0, 1} };
    //int arr2[3][3] = { {9, 1, 12},{0, 9, 1},{0, 9, 9} };

    PrintMatrix(arr, 3, 3);

    if (IsSparesMatrix(arr, 3, 3)) {
        cout << "\nYes : It's spares\n";
    }
    else {
        cout << "\nNo : It's NOT spares\n";
    }

    return 0;

}