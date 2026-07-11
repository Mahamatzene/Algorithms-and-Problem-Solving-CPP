

#include <iostream>
#include <string>
using namespace std;

string ReadText() {
    string text;

    cout << "\nPLease enter your string here : ";
    getline(cin, text);

    return text;
}

string TrimLeft(string text){
    
    for (short i = 0; i < text.length(); i++) {
        
        if (text[i] != ' ') {
            return text.substr(i, text.length() - i);
            /*i = first non - space character.
            Start from i and take all remaining characters until the end of the string.*/
        }
    }

    return " ";
}

string TrimRight(string text) {
    for (short i = text.length() - 1; i >= 0; i--) {

        if (text[i] != ' ') {
            return text.substr(0, i + 1);
            /*i = last non - space character.
            Start from index 0 and take characters up to and including index i.
            (i + 1 because substr() takes length, not ending index.)*/
        }
    }

    return " ";
}

string Trim(string text) {
    return(TrimLeft(TrimRight(text)));
}

void PrintAllTrims(string text) {
    cout << "Trim left  : " << TrimLeft(text) << endl;
    cout << "Trim right : " << TrimRight(text) << endl;
    cout << "Trim       : " << Trim(text);
}

int main()
{
    PrintAllTrims(ReadText());

    return 0;
}

