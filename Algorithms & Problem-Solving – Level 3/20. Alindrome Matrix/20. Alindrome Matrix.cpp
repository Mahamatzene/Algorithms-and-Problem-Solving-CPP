
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

bool IsPalindromeMatrix(int arr[3][3], short row, short col) {

    for (short i = 0; i < row; i++) {
        for (short j = 0; j < col / 2; j++) {
           if (arr[i][j] != arr[i][col - 1 - j]) {
               return false;
           }
        }
    }
    return true;
}

int main()
{
    int arr[3][3] = { {1, 2, 1}, {5, 5, 5}, {7, 3, 7} };

    cout << "Matrix 1 : \n";
    PrintMatrix(arr, 3, 3);

    
    if (IsPalindromeMatrix(arr, 3, 3)) {
        cout << "\nYes matrix is palindrome\n";
    }
    else {
        cout << "\nNO matrix is NOT palindrome\n";
    }
    
    return 0;
}

