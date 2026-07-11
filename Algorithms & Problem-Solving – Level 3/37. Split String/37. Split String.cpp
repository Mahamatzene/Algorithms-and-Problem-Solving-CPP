

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadText() {
    string text;

    cout << "\nPLease enter your string here : ";
    getline(cin, text);

    return text;
}

vector<string> Split(string text, string delim)
{
    short pos = 0;
    string sWord; // define a string variable
    vector<string> vSplit;

    // use find() function to get the position of the delimiters
    while ((pos = text.find(delim)) != std::string::npos)
    {
        sWord = text.substr(0, pos); // store the word
        if (sWord != " ")
        {
            vSplit.push_back(sWord);
        }
        text.erase(0, pos + delim.length()); /* erase() until
        positon and move to next word. */
    }
    // it check the last word of the string.
    if (text != " ")
    {
        vSplit.push_back(text);
    }

    return vSplit;
}

void PrintVectorElements(vector<string> vSplit) {

    cout << "\nTokens = " << vSplit.size() << endl;
    
    for (string& text : vSplit) {
        cout << text << endl; 
    }
}

int main()
{
    vector<string> vSplit = Split(ReadText(), " ");
    PrintVectorElements(vSplit);

    return 0;
}

