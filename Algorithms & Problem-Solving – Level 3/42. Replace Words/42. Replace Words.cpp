
#include <iostream>
#include <string>
using namespace std;

string ReadText(string message) {
    string text;

    cout << message;
    getline(cin, text);

    return text;
}

string ReplaceWordsInString(string text, string stringToReplace, string replaceTo)
{
    short pos = text.find(stringToReplace);

    while (pos != string::npos) {

        //pos will save the position of the stringToReplace and stringToReplace.length()
        //will give the size of the word and replace it with replaceTo
        //welcome to jordan
        // pos = 12
        // stringToReplace.length() = 6
        //this mean take from pos : 12 and replace the 6 with the replaceTo
        text = text.replace(pos, stringToReplace.length(), replaceTo);
        pos = text.find(stringToReplace);
    }

    return text;
}

int main()
{
    string S1 = ReadText("Please enter your string : ");
    string stringToReplace = ReadText("Enter what word you want to replace : ");
    string replaceTo = ReadText("Enter what you want to replace with : ");

    cout << "Original string is : \n" << S1 << endl;

    cout << "\n\nString after replacing words:";
    cout << "\n" << ReplaceWordsInString(S1, stringToReplace, replaceTo) << endl;

    return 0;
}