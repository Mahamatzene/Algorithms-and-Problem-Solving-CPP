//hire a driver case 1

#include <iostream>
using namespace std;

struct stInfo
{
    int Age;
    bool HaveADriverLicense;
};

stInfo ReadInfo()
{
    stInfo Info;

    cout << "\nPlease enter your age: " << endl;
    cin >> Info.Age;

    cout << "\nDo you have a driver license? " << endl;
    cin >> Info.HaveADriverLicense;

    return Info;
}

bool IsAccepted(stInfo Info)
{
    return (Info.Age > 21 && Info.HaveADriverLicense);
}

void PrintInfo(stInfo Info)
{
    if (IsAccepted(Info))
        cout << "\nHired" << endl;
    else
        cout << "\nRejected" << endl;
}

int main()
{
    PrintInfo(ReadInfo());

    return 0;
}
