
#include <iostream>
#include <string>
using namespace std;

struct stClientData {
    string accountnumber = "";
    string pinCode = "";
    string name = "";
    string phoneNumber = "";
    int accountBalance = 0;
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

string ConvertRecord(stClientData clientInfo, string sperater = "#//#") {
    
    string clientRecord = "";

    clientRecord += clientInfo.accountnumber + sperater;
    clientRecord += clientInfo.pinCode + sperater;
    clientRecord += clientInfo.name + sperater;
    clientRecord += clientInfo.phoneNumber + sperater;
    clientRecord += to_string(clientInfo.accountBalance) + sperater;
    
    return clientRecord;
}

int main()
{
    cout << "\nPlease enter client data :" << endl;

    stClientData clientInfo = ReadClientInfo();

    cout << "\nClient record for saving is : " << endl;
    cout << ConvertRecord(clientInfo) << endl;

    return 0;
}
