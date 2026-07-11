
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
const string ClientsFileName = "Clients.txt";

struct stClientData {
    string accountnumber = "";
    string pinCode = "";
    string name = "";
    string phoneNumber = "";
    double accountBalance = 0;
};

string ReadClientInfo() {
    string clientNumber = "";

    cout << "Please enter account number to search : ";
    cin >> clientNumber;

    return clientNumber;
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

vector<stClientData> LoadCleintsDataFromFile(string fileName) {

    fstream myFile;
    vector<stClientData> vClients;

    myFile.open(fileName, ios::in);

    if (myFile.is_open()) {
        string Line;
        stClientData clientData;

        while (getline(myFile, Line)) {

            clientData = ConvertLineToRecord(Line, "#//#");
            vClients.push_back(clientData);
        }

        myFile.close();
    }

    return vClients;
}

void PrintClientRecord(stClientData clientData) {
    cout << "\nThe following are the client details : " << endl;

    cout << "\naccount number           : " << clientData.accountnumber << endl;
    cout << "pin code                 : " << clientData.pinCode << endl;
    cout << "client name              : " << clientData.name << endl;
    cout << "client phone number      : " << clientData.phoneNumber << endl;
    cout << "client account balance   : " << clientData.accountBalance << endl;
}

bool FindClientByAccountNumber(stClientData& Clients, string clientNumber) {

    vector<stClientData> vClients = LoadCleintsDataFromFile(ClientsFileName);

    for (stClientData client : vClients) {
        if (client.accountnumber == clientNumber) {
            
            Clients = client;
            return true;
        }
    }

    return false;
}

int main()
{
    string clientNumber = ReadClientInfo();
    stClientData Clients;

    if (FindClientByAccountNumber(Clients, clientNumber)) {
        PrintClientRecord(Clients);
    }
    else {
        cout << "\nClient with number (" << clientNumber << ") is NOT found !" << endl;
    }

    return 0;
}