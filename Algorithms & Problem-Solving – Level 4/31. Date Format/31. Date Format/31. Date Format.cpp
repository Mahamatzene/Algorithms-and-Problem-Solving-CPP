
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stDate {
    short Year = 0;
    short Month = 0;
    short Day = 0;
};

string ReadStringDate()
{
    string DateString;
    cout << "Please enter a date dd/mm/yyyy : ";
    getline(cin >> ws, DateString);
    return DateString;
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

string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo) {
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(),
            sRepalceTo);
        pos = S1.find(StringToReplace);//find next
    }
    return S1;
}

stDate ConvertStringToDate(vector<string> vDate) {
    stDate date;

    date.Day = stoi(vDate[0]);
    date.Month = stoi(vDate[1]);
    date.Year = stoi(vDate[2]);

    return date;
}

void PrintDates(stDate date, string sDate) {

    cout << "\nDay : " << date.Day << endl;
    cout << "Month : " << date.Month << endl;
    cout << "Year : " << date.Year << endl;

    cout << "\nYou entered : " << sDate << endl;
}

string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy") {
    string FormattedDateString = "";

    FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));

    return FormattedDateString;
}

int main()
{
    stDate Date;
    string dateString = ReadStringDate();

    vector<string> vDate;
    vDate.push_back(dateString);

    Date = ConvertStringToDate(Split(dateString, "/"));

    cout << "\n" << FormateDate(Date) << "\n";

    cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << "\n";
    cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";

    return 0;

}