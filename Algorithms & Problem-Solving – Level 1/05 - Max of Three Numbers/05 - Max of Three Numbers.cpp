
#include <iostream>
using namespace std;


struct stInfo
{
    int age;
    bool hasDrivingLicense;
    bool hasRecommendation;
};

stInfo readInfo()
{
    stInfo info;

    cout << "do you have recommendation?" << endl;
    cin >> info.hasRecommendation;

    cout << "please enter your age" << endl;
    cin >> info.age;

    cout << "do you have a drivrer license?" << endl;
    cin >> info.hasDrivingLicense;

    return info;
}

bool isAccepted(stInfo info)
{
    if (info.hasRecommendation)
    {
        return true;
    }
    else
    {
        return (info.age > 21 && info.hasDrivingLicense);
    }
};

void printResult(stInfo info)
{
    if (isAccepted(info))
        cout << "\n hired" << endl;
    else
        cout << "\n rejected" << endl;
}

int main()
{
    printResult(readInfo());

    return 0;
}

