

#include <iostream>
#include <string>
using namespace std;

string ReadText() {
    string text;

    cout << "\nPLease enter your string here : ";
    getline(cin, text);

    return text;
}

bool CheckVowelLetter(char letterToCheck) {
    letterToCheck = tolower(letterToCheck);

    return ((letterToCheck == 'a') || (letterToCheck == 'e') || (letterToCheck == 'i') || (letterToCheck == 'o') || (letterToCheck == 'u'));

}

void PrintVowelLetters(string text) {

    cout << "\nVowel in string are : ";

    for (short i = 0; i < text.length(); i++) {
        if (CheckVowelLetter(text[i]))
            cout << text[i] << "    ";
    }
}

int main()
{
    string text = ReadText();

    PrintVowelLetters(text);
    
    return 0;
}

