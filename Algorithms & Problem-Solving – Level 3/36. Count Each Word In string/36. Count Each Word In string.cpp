

#include <iostream>
#include <string>
using namespace std;

string ReadText() {
    string text;

    cout << "\nPLease enter your string here : ";
    getline(cin, text);

    return text;
}

short CountHowManyWordInString(string text)
{
    short counter = 0;
    string delim = " "; // delimiter
    short pos = 0;
    string sWord; // define a string variable

    // use find() function to get the position of the delimiters
    while ((pos = text.find(delim)) != std::string::npos)
    {
        sWord = text.substr(0, pos); // store the word
        if (sWord != "")
        {
            counter++;
        }
        text.erase(0, pos + delim.length()); /* erase() until
        positon and move to next word. */
    }
    if (text != "")
    {
        counter++;
     // it check the last word of the string.
    }

    return counter;
}

int main()
{
    string text = ReadText();

    cout << "\nThe number of word in your text is : " << CountHowManyWordInString(text) << endl;

    return 0;
}

