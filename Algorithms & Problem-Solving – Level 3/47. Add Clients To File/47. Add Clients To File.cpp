
#include <iostream>
#include <fstream>
#include <string>
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

stClientData ReadClientInfo() {

    stClientData clientData;

    cout << "Enter account number : ";
    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, clientData.accountnumber);

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

string ConvertRecordToLine(stClientData clientInfo, string sperator) {

    string clientRecord = "";

    clientRecord += clientInfo.accountnumber + sperator;
    clientRecord += clientInfo.pinCode + sperator;
    clientRecord += clientInfo.name + sperator;
    clientRecord += clientInfo.phoneNumber + sperator;
    clientRecord += to_string(clientInfo.accountBalance);

    return clientRecord;
}

void AddDataLineToFile(string fileName, string dataLine) {
    fstream myFile;
    myFile.open(fileName, ios::out | ios::app);

    if (myFile.is_open()) {

        myFile << dataLine << endl;
        myFile.close();
    }
}

void AddNewClient() {
    stClientData clientData = ReadClientInfo();
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(clientData, "#//#"));
}

void AddClient() {
    char AskAgain = 'Y';


    do {
        system("cls");
        cout << "Adding new client:\n" << endl;

        AddNewClient();

        cout << "Do you want to add another client? [Y] yes. [N] no." << endl;
        cout << "Please enter your choice here : ";
        cin >> AskAgain;

        

    } while (toupper(AskAgain) == 'Y');
}

int main()
{
    AddClient();

    return 0;
}