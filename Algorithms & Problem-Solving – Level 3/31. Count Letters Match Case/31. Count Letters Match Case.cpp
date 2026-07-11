
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

char InvertLetterCase(char charachter) {
    return (isupper(charachter)) ? tolower(charachter) : toupper(charachter);
}

//matchCase variable is going to seperet the function work if we need to do for exapmle m == m or not
//if it's true we just check if m == m
//if it's false we will check if m == M 
short CountLetter(string text, char letterToCheck, bool matchCase = true) {
    short count = 0;

    for (short i = 0; i < text.length(); i++) {
        //metchChase == true? if yes do m == m, if no go to else and do m == M
        if (matchCase) {
            if (text[i] == letterToCheck)
                count++;
        }
        else {
            //Converts both letters to lowercase before comparison so uppercase and lowercase 
            // are treated as the same character.
            if (tolower(text[i]) == tolower(letterToCheck))
                count++;
        }
    }

    return count;
}

int main()
{
    string text = ReadText();
    char letterToCheck = ReadLetter();

    cout << "\nLetter '" << letterToCheck << "' count " << CountLetter(text, letterToCheck) << " times\n";
    cout << "\nLetter '" << letterToCheck << "' or '" << InvertLetterCase(letterToCheck) <<"' count " << CountLetter(text, letterToCheck, false) << " times\n";

    return 0;
}