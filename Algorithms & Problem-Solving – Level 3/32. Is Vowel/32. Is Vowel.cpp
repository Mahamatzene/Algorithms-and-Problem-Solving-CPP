
#include <iostream>
#include <string>
using namespace std;

char ReadLetter() {
    char letterToCheck;

    cout << "\nEnter letter to check : ";
    cin >> letterToCheck;

    return letterToCheck;
}

bool CheckVowelLetter(char letterToCheck) {
    letterToCheck = tolower(letterToCheck);

    return ((letterToCheck == 'a') || (letterToCheck == 'e') || (letterToCheck == 'i') || (letterToCheck == 'o') || (letterToCheck == 'u'));

}

int main()
{
    char letterToCheck = ReadLetter();

    if (CheckVowelLetter(letterToCheck))
        cout << "\nYes : letter '" << letterToCheck << "' is vowel\n";
    else
        cout << "\nNo : letter '" << letterToCheck << "' is NOT vowel\n";

    return 0;
}