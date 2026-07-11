
#include <iostream>
#include <string>
using namespace std;

string RemoveAllPauncuations(string text)
{
    string text2 = "";

    for (short i = 0; i < text.length(); i++){
        if (!ispunct(text[i])) {
            text2 += text[i];
        }
    }
    return text2;
}

int main()
{
    string text = "Welcome to Jordan, Jordan is a nice country; it's amazing.";

    cout << "Original string is : \n" << text;

    cout << "\n\nPauncuation removed : " << endl;
    cout << RemoveAllPauncuations(text) << endl;

    return 0;
}