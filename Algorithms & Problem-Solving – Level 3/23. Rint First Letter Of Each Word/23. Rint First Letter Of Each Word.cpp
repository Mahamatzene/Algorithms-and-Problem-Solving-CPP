

#include <iostream>
#include <string>
using namespace std;

string ReadText() {
    string text;

    cout << "Please enter your string here : ";
    getline(cin, text);

    return text;
}

void PrintFirstLetterInText(string text) {
    bool isFirstLetter = true;

    for (char i = 0; i < text.size(); i++) {
        if (text[i] != ' ' && isFirstLetter) {
            cout << text[i] << endl;
        }

        isFirstLetter = (text[i] == ' ' ? true : false);
    }
}

int main()
{
    PrintFirstLetterInText(ReadText());

    return 0;
}