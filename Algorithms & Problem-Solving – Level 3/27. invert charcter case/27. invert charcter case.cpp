

#include <iostream>
#include <string>
using namespace std;

char ReadText() {
    char charachter;

    cout << "Please enter a character here : ";
    cin >> charachter;

    return charachter;
}

char InvertLetterCase(char charachter) {
    return isupper(charachter) ? tolower(charachter) : toupper(charachter);
}
    
int main()
{
    char charachter = ReadText();

    cout << "\nchar after inverting case :\n";
    charachter = InvertLetterCase(charachter);
    cout << charachter;

    return 0;
}