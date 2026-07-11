
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stClientData {
    string accountnumber = "";
    string pinCode = "";
    string name = "";
    string phoneNumber = "";
    double accountBalance = 0;
};

stClientData ReadClientInfo() {

    stClientData clientData;


    cout << "Enter account number : ";
    getline(cin, clientData.accountnumber);

    cout << "Enter pin code : ";
    getline(cin, clientData.pinCode);

    cout << "Enter client name : ";
    getline(cin, clientData.name);

    cout << "Enter client phone number : ";
    getline(cin, clientData.phoneNumber);

    cout << "Enter client account balance : ";
    cin >> clientData.accountBalance;

    return clientData;
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

string ConvertRecordToLine(stClientData clientInfo, string sperater = "#//#") {

    string clientRecord = "";

    clientRecord += clientInfo.accountnumber + sperater;
    clientRecord += clientInfo.pinCode + sperater;
    clientRecord += clientInfo.name + sperater;
    clientRecord += clientInfo.phoneNumber + sperater;
    clientRecord += to_string(clientInfo.accountBalance);

    return clientRecord;
}

stClientData ConvertLineToRecord(string line, string speator) {

    stClientData client;
    vector<string> vClientData = Split(line, speator);

    client.accountnumber = vClientData[0];
    client.pinCode = vClientData[1];
    client.name = vClientData[2];
    client.phoneNumber = vClientData[3];
    client.accountBalance = stod(vClientData[4]);

    return client;
}

void PrintClientRecord(stClientData clientData) {
    cout << "\nThe following is the extracted client record : " << endl;

    cout << "\naccount number           : " << clientData.accountnumber << endl;
    cout << "pin code                 : " << clientData.pinCode << endl;
    cout << "client name              : " << clientData.name << endl;
    cout << "client phone number      : " << clientData.phoneNumber << endl;
    cout << "client account balance   : " << clientData.accountBalance << endl;
}

int main()
{
    cout << "\nPlease enter client data :" << endl;

    stClientData clientInfo = ReadClientInfo();
    string clientRecord = ConvertRecordToLine(clientInfo);

    cout << "\nLine record is : " << endl;
    cout << clientRecord << endl;

    ConvertLineToRecord(clientRecord, "#//#");
    PrintClientRecord(clientInfo);

    return 0;
}
