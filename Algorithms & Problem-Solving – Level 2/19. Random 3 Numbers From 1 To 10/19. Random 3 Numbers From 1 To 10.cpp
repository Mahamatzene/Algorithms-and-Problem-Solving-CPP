

#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharType { CapitelLetter = 1, SmallLetter = 2, SpecialCharacter = 3, Digit = 4 };

int Random(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}


char GetRandomCharacter(enCharType charType)
{
    switch (charType)
    {
    case enCharType::CapitelLetter:
        return char(Random(65, 90));
        break;
    case enCharType::SmallLetter:
        return char(Random(97, 122));
        break;
    case enCharType::SpecialCharacter:
        return char(Random(32, 47));
        break;
    case enCharType::Digit:
        return char(Random(48, 57));
        break;
    default:
        return char(Random(48, 57));
    }
}

int main()
{
    srand((unsigned)time(NULL));

    cout << GetRandomCharacter(enCharType::SmallLetter) << endl;
    cout << GetRandomCharacter(enCharType::CapitelLetter) << endl;
    cout << GetRandomCharacter(enCharType::SpecialCharacter) << endl;
    cout << GetRandomCharacter(enCharType::Digit) << endl;

    return 0;
}

