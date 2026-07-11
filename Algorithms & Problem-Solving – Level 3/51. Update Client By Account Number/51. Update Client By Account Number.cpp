
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

string ReadClientNumber() {
    string clientNumber = "";

    cout << "Please enter account number to search : ";
    cin >> clientNumber;

    return clientNumber;
}

stClientData ReadClientInfo() {

    stClientData clientData;

    cout << "Enter pin code : ";
    getline(cin >> ws, clientData.pinCode);

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

string ConvertRecordToLine(stClientData clientInfo, string sperator) {

    string clientRecord = "";

    clientRecord += clientInfo.accountnumber + sperator;
    clientRecord += clientInfo.pinCode + sperator;
    clientRecord += clientInfo.name + sperator;
    clientRecord += clientInfo.phoneNumber + sperator;
    clientRecord += to_string(clientInfo.accountBalance);

    return clientRecord;
}

stClientData ConvertLineToRecord(string line, string speator) {

    stClientData client;
    vector<string> vClientData = Split(line, speator);

    if (vClientData.size() < 5) {
        return client;
    }

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

void PrintClientCard(stClientData clientData) {
    cout << "\nThe following are the client details : " << endl;

    cout << "\naccount number           : " << clientData.accountnumber << endl;
    cout << "pin code                 : " << clientData.pinCode << endl;
    cout << "client name              : " << clientData.name << endl;
    cout << "client phone number      : " << clientData.phoneNumber << endl;
    cout << "client account balance   : " << clientData.accountBalance << endl;
}

bool FindClientByAccountNumber(vector<stClientData> vClients, stClientData& Clients, string clientNumber) {

    for (stClientData client : vClients) {
        if (client.accountnumber == clientNumber) {

            Clients = client;
            return true;
        }
    }

    return false;
}

bool MarkClientForDeleteByAccountNumber(string accountNumber, vector<stClientData>& vClient) {
    for (stClientData& client : vClient) {
        if (client.accountnumber == accountNumber) {
            /*client.markForDelete = true;*/
            return true;
        }
    }

    return false;
}

vector<stClientData> SaveClientDataToFile(string fileName, vector<stClientData> vFileContent) {
    fstream myFile;
    string dataLine;
    myFile.open(ClientsFileName, ios::out);

    if (myFile.is_open()) {

        for (stClientData client : vFileContent) {

            dataLine = ConvertRecordToLine(client, "#//#");
            myFile << dataLine << endl;
            /*if (client.markForDelete == false) {
                dataLine = ConvertRecordToLine(client, "#//#");
                myFile << dataLine << endl;
            }*/
        }

        myFile.close();
    }

    return vFileContent;
}

void UpdateClientInfo(vector<stClientData>& vClient, string clientNumber) {
    stClientData newClient;

    for (stClientData& client : vClient) {
        if (client.accountnumber == clientNumber) {
            newClient = ReadClientInfo();
            //newClient.accountnumber = client.accountnumber;
            //vClient.push_back(newClient);
            client.pinCode = newClient.pinCode;
            client.name = newClient.name;
            client.phoneNumber = newClient.phoneNumber;
            client.accountBalance = newClient.accountBalance;
            break;
        }
    }
}

bool UpdateClientByAccountNumber(vector<stClientData>& vClients, string clientNumber) {
    stClientData client;
    char answer = 'n';

    if (FindClientByAccountNumber(vClients, client, clientNumber)) {
        PrintClientCard(client);

        cout << "\nAre you sure you want to update this client? y/n" << endl;
        cout << "Please enter your choice here : ";
        cin >> answer;

        if (toupper(answer) == 'Y') {
            //MarkClientForDeleteByAccountNumber(clientNumber, vClients);
            UpdateClientInfo(vClients, clientNumber);
            SaveClientDataToFile(ClientsFileName, vClients);

            vClients = LoadCleintsDataFromFile(ClientsFileName);

            cout << "\nClient UPDATED successfuly." << endl;
            return true;
        }
    }
    else {
        cout << "\nClient with number (" << clientNumber << ") is NOT found !" << endl;
        return false;
    }
}

int main()
{
    string clientNumber = ReadClientNumber();
    vector<stClientData> vClients = LoadCleintsDataFromFile(ClientsFileName);
    UpdateClientByAccountNumber(vClients, clientNumber);

    return 0;
}