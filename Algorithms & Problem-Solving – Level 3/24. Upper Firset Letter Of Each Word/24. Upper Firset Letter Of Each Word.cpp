

#include <iostream>
#include <string>
using namespace std;

string ReadText() {
    string text;

    cout << "Please enter your string here with small letters : ";
    getline(cin, text);

    return text;
}

string UpperFirstLetterOfEachWord(string text) {
    bool isFirstLetter = true;


    for (char i = 0; i < text.size(); i++) {
        if (text[i] != ' ' && isFirstLetter) {
            text[i] = toupper(text[i]);
        }

        isFirstLetter = (text[i] == ' ' ? true : false);
    }
    return text;
}

int main()
{
    string text = ReadText();

    cout << "\nString after conversion:\n";
    text = UpperFirstLetterOfEachWord(text);
    cout << text << endl;

    return 0;
}