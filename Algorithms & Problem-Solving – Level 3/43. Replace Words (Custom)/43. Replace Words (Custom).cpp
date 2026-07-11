
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadText(string message) {
    string text;

    cout << message;
    getline(cin, text);

    return text;
}

vector<string> SplitString(string text, string delim)
{
    short pos = 0;
    string sWord;
    vector<string> vSplit;


    while ((pos = text.find(delim)) != std::string::npos)
    {
        sWord = text.substr(0, pos);
        if (sWord != " ")
        {
            vSplit.push_back(sWord);
        }
        text.erase(0, pos + delim.length());
    }

    if (text != " ")
    {
        vSplit.push_back(text);
    }

    return vSplit;
}

string JoinString(vector<string> vString, string Delim)
{
    string S1;
    for (string& s : vString)
    {
        S1 = S1 + s + Delim;
    }
    return S1.substr(0, S1.length() - Delim.length());
}

string LowerAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}

string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
{
    vector<string> vString = SplitString(S1, " ");
    for (string& newText : vString)
    {
        if (MatchCase)
        {
            if (newText == StringToReplace)
            {
                newText = sRepalceTo;
            }
        }
        else
        {
            if (LowerAllString(newText) == LowerAllString(StringToReplace))
            {
                newText = sRepalceTo;
            }
        }
    }
    return JoinString(vString, " ");
}

int main()
{
    string text = "Welcome to Jordan , Jordan is a nice country";
    string stringToReplace = "jordan";
    string replaceTo = "USA";

    cout << "Original string is : \n" << text;   
    

    cout << "\n\nReplace with match case : " << endl;
    cout << ReplaceWordInStringUsingSplit(text, stringToReplace, replaceTo);

    cout << "\n\nReplace with don't match case : " << endl;
    cout << ReplaceWordInStringUsingSplit(text, stringToReplace, replaceTo, false) << endl;

    return 0;
}