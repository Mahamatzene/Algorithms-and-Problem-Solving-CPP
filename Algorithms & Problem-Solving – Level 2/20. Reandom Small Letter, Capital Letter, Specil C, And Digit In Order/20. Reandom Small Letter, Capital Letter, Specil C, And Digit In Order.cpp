
#include <iostream>
#include <cstdlib>
using namespace std;


int RandomeNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SmallLetter:
        return char(RandomeNumber(97, 122));
        break;
    case enCharType::CapitalLetter:
        return char(RandomeNumber(65, 90));
        break;
    case enCharType::SpecialCharacter:
        return char(RandomeNumber(33, 47));
        break;
    case enCharType::Digit:
        return char(RandomeNumber(48, 57));
        break;
    default:
        return char(RandomeNumber(65, 90));
    }
}

int main()
{
    srand((unsigned)time(NULL));

    cout << GetRandomCharacter(enCharType::SmallLetter) << endl;
    cout << GetRandomCharacter(enCharType::CapitalLetter) << endl;
    cout << GetRandomCharacter(enCharType::SpecialCharacter) << endl;
    cout << GetRandomCharacter(enCharType::Digit) << endl;

    return 0;
}

