

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

int RandomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}

char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SmallLetter:
        return char(RandomNumber(97, 122));
        break;
    case enCharType::CapitalLetter:
        return char(RandomNumber(65, 90));
        break;
    case enCharType::SpecialCharacter:
        return char(RandomNumber(33, 47));
        break;
    case enCharType::Digit:
        return char(RandomNumber(48, 57));
        break;
    default:
        return char(RandomNumber(65, 90));
    }
}

void PrintStringArray(string arr[100], int arrLength)
{
    cout << "\nArray elements:\n\n";

    for (int i = 0; i < arrLength; i++)
    {
        cout << "Array [" << i << "] : ";
        cout << arr[i] << "\n";
    }

    cout << "\n";
}

string GenerateWord(enCharType charType, short length)
{
    string word = "";

    for (int i = 1; i <= length; i++)
    {
        word += GetRandomCharacter(charType);
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

void FillArrayWithKeys(string arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = GenerateKey();
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

int main()
{
    srand((unsigned)time(NULL));

    string arr[100];
    int arrLength = 0;

    arrLength = ReadPositiveNumber("please enetr how many keys do you wnat to generate ?");

    FillArrayWithKeys(arr, arrLength);

    PrintStringArray(arr, arrLength);

    return 0;
}


