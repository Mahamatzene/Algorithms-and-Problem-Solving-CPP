

#include <iostream>
#include <string>
using namespace std;

string ReadText() {
    string text;

    cout << "Please enter your string here with CAPITAL letters : ";
    getline(cin, text);

    return text;
}

string LowerAllLettersInWord(string text) {
    for (char i = 0; i < text.size(); i++) {
        if (text[i] != ' ') {
            text[i] = tolower(text[i]);
        }
    }
    return text;
}

string UpperAllLettersInWord(string text) {
    for (char i = 0; i < text.size(); i++) {
        if (text[i] != ' ') {
            text[i] = toupper(text[i]);
        }
    }
    return text;
}

int main()
{
    string text = ReadText();

    cout << "\nString after upper:\n";
    text = UpperAllLettersInWord(text);
    cout << text << endl;

    cout << "\nString after lower:\n";
    text = LowerAllLettersInWord(text);
    cout << text << endl;

    return 0;
}