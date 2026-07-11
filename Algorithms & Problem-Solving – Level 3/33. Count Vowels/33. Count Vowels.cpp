

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

short CountVowelLetters(string text) {
    short counter = 0;

    for (short i = 0; i < text.length(); i++) {
        if (CheckVowelLetter(text[i])) {
            counter++;
        }
    }

    return counter;
}

int main()
{
    string text = ReadText();

    cout << "\nNumber of vowel is : " << CountVowelLetters(text) << endl;

    return 0;
}

