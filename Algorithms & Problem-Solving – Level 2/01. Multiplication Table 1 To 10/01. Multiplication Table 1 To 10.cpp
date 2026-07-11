//print Multipliaction Table From 1 to 10

#include <iostream>
using namespace std;

void PrintTableHeader()
{
    cout << "\n\n\t\t Multipliaction Table From 1 to 10\t\t\n" << endl;

    for (int i = 1; i <= 10; i++)
    {

        cout << "\t" << i;

    }
    cout << "\n-----------------------------------------------------------------------------------\n";

}

string ColumnSperator(int i)
{
    if (i < 10)
        return "  |";
    else
        return " |";
}

void PrintMultipliactionTableFrom1to10()
{
    PrintTableHeader();

    for (int i = 1; i <= 10; i++)
    {
        cout << " " << i << ColumnSperator(i) << "\t";

        for (int j = 1; j <= 10; j++)
        {
            cout << i * j << "\t";
            
        }

        cout << endl;
    }
}

int main()
{
    PrintMultipliactionTableFrom1to10();
    
    return 0;
}


