

#include <iostream>
#include <string>
using namespace std;

string ReadText() {
    string text;

    cout << "\nPLease enter your string here : ";
    getline(cin, text);

    return text;
}

//mine
//void PrintEachWord(string text) {
//
//    cout << "\nYour text words are :\n\n";
//
//    for (short i = 0; i < text.length(); i++) {
//        if (text[i] == ' ') {
//            cout << endl;
//        }
//        else {
//            cout << text[i];
//        }
//    }
//
//    cout << endl;
//}

void PrintEachWordInString(string text)
{
    string delim = " "; // delimiter
    cout << "\nYour string wrords are: \n\n";
    short pos = 0;
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters
    while ((pos = text.find(delim)) != std::string::npos)
    {
        sWord = text.substr(0, pos); // store the word
        if (sWord != "")
        {
            cout << sWord << endl;
        }
        text.erase(0, pos + delim.length()); /* erase() until
        positon and move to next word. */
    }
    if (text != "")
    {
        cout << text << endl; // it print last word of the string.
    }
}

int main()
{
    PrintEachWordInString(ReadText());

    return 0;
}

