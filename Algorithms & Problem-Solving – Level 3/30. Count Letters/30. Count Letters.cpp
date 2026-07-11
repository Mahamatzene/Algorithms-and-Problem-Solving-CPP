
#include <iostream>
#include <string>
using namespace std;

string ReadText() {
    string text;

    cout << "\nPLease enter your string here : ";
    getline(cin, text);

    return text;
}

char ReadLetter() {
    char letterToCheck;

    cout << "\nEnter letter to check : ";
    cin >> letterToCheck;

    return letterToCheck;
}

short CountLetterInString(string text, char letterToCheck) {
    short count = 0;
    for (short i = 0; i < text.length(); i++) {
        if (text[i] == letterToCheck)
            count++;
    }

    return count;
}

int main()
{
    string text = ReadText();
    char letterToCheck = ReadLetter();

    cout << "\nLetter '" << letterToCheck << "' count " << CountLetterInString(text, letterToCheck) << " times\n";
}