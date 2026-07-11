

#include <iostream>
using namespace std;

struct stInfo
{
    string firstName;
    string lastName;
};

stInfo ReadInfo()
{
    stInfo Info;

    cout << "\nPlease enter your first name : " << endl;
    cin >> Info.firstName;

    cout << "\nPlease enter your last name : " << endl;
    cin >> Info.lastName;

    return Info;
}

string GetFullName(stInfo Info)
{
    string FullName = "";

    FullName = Info.firstName + " " + Info.lastName;

    return FullName;
}

string GetFullName(stInfo Info, bool Reversed)
{
    //we will use this function if we want to reverse the name as amarican pepole

    string FullName = "";

    if (Reversed)
        FullName = Info.lastName + " " + Info.firstName;
    else
        FullName = Info.firstName + " " + Info.lastName;

    return FullName;
}

void PrintFullName(string FullName)
{
    cout << "\nYour full name is : " << FullName << endl;
}

int main()
{
    PrintFullName(GetFullName(ReadInfo()));

    PrintFullName(GetFullName(ReadInfo(), true)); // we will use this if we want to reverse and add true to reverse it

    return 0;
}


