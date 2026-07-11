
#include <iostream>
#include <iomanip>
using namespace std;

int ReadNumber() {
    int num = 0;

    do {
        cout << "\nPlease enter the number to count in matrix : ";
        cin >> num;
    } while (num < 0);

    return num;
}

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

void PrintMatrix(int arr[3][3], short rows, short cols) {

    cout << "Matrix 1 : \n";

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            printf("%0*d\t", 2, arr[i][j]);

        }
        cout << "\n";
    }
}

int main()
{
    int arr[3][3] = { {9, 1, 12},{0, 9, 1},{0, 9, 9} };

    PrintMatrix(arr, 3, 3);

    int Number;
    cout << "\nEnter the number to count in matrix? ";
    cin >> Number;

    cout << "\nNumber " << Number << " count in matrix is "
        << CountNumberInMatrix(arr, Number, 3, 3);

    return 0;

}