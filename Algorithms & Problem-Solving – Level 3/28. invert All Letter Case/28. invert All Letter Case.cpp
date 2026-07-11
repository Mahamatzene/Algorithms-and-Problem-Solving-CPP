#include <iostream>
#include <string>
using namespace std;

string ReadText() {
    string text;

    cout << "Please enter your string here : ";
    getline(cin, text);

    return text;
}

char InvertLetterCase(char char1){
    return isupper(char1) ? tolower(char1) : toupper(char1);
}

string InvertAllLatterCase(string text) {
    for (short i = 0; i < text.length(); i++) {
        text[i] = InvertLetterCase(text[i]);
    }

    return text;
}

int main()
{
    string text = ReadText();
    text = InvertAllLatterCase(text);
    cout << text << endl;
}