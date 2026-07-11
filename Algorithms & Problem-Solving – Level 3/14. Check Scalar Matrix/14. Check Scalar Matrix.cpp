
#include <iostream>
#include <iomanip>
using namespace std;

void PrintMatrix(int arr[3][3], short rows, short cols) {

    cout << "Matrix 1 : \n";

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

bool IsScalarMarix(int arr[3][3], short rows, short cols) {

    //check Diagonal elements are 1 and rest elements are 0
    int scalar = arr[0][0];
    for (short i = 0; i < rows; i++) {
        for (short j = 0; j < cols; j++) {
            //check for diagonals element
            if (i == j && arr[i][j] != scalar) {
                return false;
            }
            //check for rest elements
            else if (i != j && arr[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int arr[3][3] = { {9, 0, 0},{0, 9, 0},{0, 0, 9} };

    PrintMatrix(arr, 3, 3);

    if (IsScalarMarix(arr, 3, 3))
        cout << "\nYES: Matrix is scalar.";
    else
        cout << "\nNo: Matrix is NOT scalar.";

    return 0;

}