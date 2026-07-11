
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

    cout << left << "|" << setw(16) << clientData.accountnumber;
    cout << left << "|" << setw(10) << clientData.pinCode;
    cout << left << "|" << setw(30) << clientData.name;
    cout << left << "|" << setw(16) << clientData.phoneNumber;
    cout << left << "|" << setw(16) << clientData.accountBalance << "|" << endl;
}

void PrintAllClientsData(vector<stClientData> vClients) {

    cout << "\n\t\t\t\tClient List (" << vClients.size() << ") Clients.\n\n";
    cout << "|--------------------------------------------------------------------------------------------|" << endl;
    cout << left << "|" << setw(16) << "Account Number";
    cout << left << "|" << setw(10) << "Pin Code";
    cout << left << "|" << setw(30) << "Client Name";
    cout << left << "|" << setw(16) << "Phone Number";
    cout << left << "|" << setw(16) << "Account Balance" << "|" << endl;
    cout << "|--------------------------------------------------------------------------------------------|" << endl;

    for (stClientData clientData : vClients) {

        PrintClientRecord(clientData);
        cout << "|--------------------------------------------------------------------------------------------|" << endl;
    }
}


int main()
{
    vector<stClientData> vClients = LoadCleintsDataFromFile(ClientsFileName);
    
    PrintAllClientsData(vClients);

    return 0;
}