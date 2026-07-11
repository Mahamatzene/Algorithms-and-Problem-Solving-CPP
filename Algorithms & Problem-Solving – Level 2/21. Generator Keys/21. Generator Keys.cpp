

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

int RandomeNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}

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

int ReadPositiveNumber(string message)
{
    int number = 0;

    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);

    return number;
}

string GenerateWord(enCharType CharType, short length)
{
    string word = "";

    for (int i = 1; i <= length; i++)
    {
        word += GetRandomCharacter(CharType);
    }

    return word;
}

string GenerateKey()
{
    string key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
    key += GenerateWord(enCharType::CapitalLetter, 4);

    return key;
}

void GenerateKeys(short numberOfKey)
{
    for (int i = 1; i <= numberOfKey; i++)
    {
        cout << "key [" << i << "] : ";
        cout << GenerateKey() << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    GenerateKeys(ReadPositiveNumber("please enter a positive number"));

    return 0;
}

