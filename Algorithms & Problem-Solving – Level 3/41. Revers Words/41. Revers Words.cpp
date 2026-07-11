
#include <iostream>
#include <vector>
#include <string>
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

string ReverseWordsInString(string S1)
{
    vector<string> vString;
    string S2 = "";
    vString = Split(S1, " ");
    // declare iterator
    vector<string>::iterator iter = vString.end();
    while (iter != vString.begin())
    {
        --iter;
        S2 += *iter + " ";
    }
    S2 = S2.substr(0, S2.length() - 1); //remove last space.
    return S2;


    /*
    begin() -> first element

    end() -> position after the last element
    
    *iter -> current element
    
    ++iter -> move forward
    
    --iter -> move backward
    */
}

int main()
{
    string S1 = ReadText();

    cout << "\n\nString after reversing words:";
    cout << "\n" << ReverseWordsInString(S1);

    return 0;
}