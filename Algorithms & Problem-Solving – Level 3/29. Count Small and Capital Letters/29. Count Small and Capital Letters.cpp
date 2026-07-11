
#include <iostream>
#include <string>
using namespace std;

string ReadText() {
    string text;

    cout << "\nPlease enter your string here : ";
    getline(cin, text);

    return text;
}

short CountCapitallLetter(string text) {
    short count = 0;
    for (short i = 0; i < text.length(); i++) {
        if (isupper(text[i])) {
          count++;
        }
    }

    return count;
}

short CountSmallLetter(string text) {
    short count = 0;
    for (short i = 0; i < text.length(); i++) {
        if (islower(text[i])) {
            count++;
        }
    }

    return count;
}

int main()
{
    string text = ReadText();

    cout << "\nString length : " << text.length() << endl;
    cout << "\nCapital letters count = " << CountCapitallLetter(text) << endl;
    cout << "\nSmall letters count = " << CountSmallLetter(text) << endl;

    return 0;
}


