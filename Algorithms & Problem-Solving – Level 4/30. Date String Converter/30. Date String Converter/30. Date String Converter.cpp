
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stDate {
    short Year = 0;
    short Month = 0;
    short Day = 0;
};

string ReadDateString() {
    string dateString = "";

    cout << "Please enter a date dd/mm/yyyy : ";
    cin >> dateString;

    return dateString;

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

stDate ConvertStringToDate(vector<string> vDate) {
    stDate date;

    date.Day = stoi(vDate[0]);
    date.Month = stoi(vDate[1]);
    date.Year = stoi(vDate[2]);
    
    return date;
}

string ConvertDateToString(stDate date) {
    return to_string(date.Day) + "/" + to_string(date.Month) + "/" + to_string(date.Year);
}

void PrintDates(stDate date, string sDate) {

    cout << "\nDay : " << date.Day << endl;
    cout << "Month : " << date.Month << endl;
    cout << "Year : " << date.Year << endl;

    cout << "\nYou entered : " << sDate << endl;
}

int main()
{
    cout << "Please enter Period 1" << endl;
    stDate date;

    string dateString = ReadDateString();

    vector<string> vDate;
    vDate.push_back(dateString);

    date = ConvertStringToDate(Split(dateString, "/"));
    dateString = ConvertDateToString(date);

    PrintDates(date, dateString);

    return 0;

}